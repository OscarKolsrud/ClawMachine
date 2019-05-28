<?php
error_reporting(0);
ini_set('display_errors', 0);
session_start();
require "assets/vendor/autoload.php";
$checkoutsession = $_SESSION["stripeID"];

$mysqli = new mysqli("localhost","kolsrudw_claw","PASSORD","kolsrudw_claw_machine") or die($mysqli->error);
$mysqli->set_charset("utf8mb4");

\Stripe\Stripe::setApiKey("sk_test_XXXXXXXXXXXXXXX");

$gameID = $mysqli->escape_string(strip_tags($_GET["game"]));
$gameHash = $mysqli->escape_string(strip_tags($_GET["hash"]));

$ensure = $mysqli->query("SELECT * FROM games WHERE stripe='$gameID' AND hash='$gameHash'") or die($mysqli->error);

if ($ensure->num_rows == 1) {
  $gameData = $ensure->fetch_assoc();
  if ($gameData["finished"] == "0") {
    $game = true;
    if ($_GET["action"] == "start_game") {
      $mysqli->query("UPDATE `games` SET `finished` = '1' WHERE `games`.`stripe` = '$gameID'");
      $gameStarted = true;

      $curl = curl_init();

      curl_setopt_array($curl, array(
        CURLOPT_URL => "https://BROKERID:PASSORD@broker.shiftr.io/game/online",
        CURLOPT_RETURNTRANSFER => true,
        CURLOPT_ENCODING => "",
        CURLOPT_MAXREDIRS => 10,
        CURLOPT_TIMEOUT => 30,
        CURLOPT_HTTP_VERSION => CURL_HTTP_VERSION_1_1,
        CURLOPT_CUSTOMREQUEST => "POST",
        CURLOPT_POSTFIELDS => "start_game",
        CURLOPT_HTTPHEADER => array(
          "cache-control: no-cache"
        ),
      ));

      $response = curl_exec($curl);
      $err = curl_error($curl);

      curl_close($curl);
    }
  } else {
    $game = false;
    $errormsg = "spillkupongen er allerede brukt!";
  }
} else {
  $game = false;
  $errormsg = "vi fant ikke noe spill med den IDen!";
}
 ?>
 <!DOCTYPE html>
 <!--[if lt IE 7]> <html class="lt-ie9 lt-ie8 lt-ie7" lang="en"> <![endif]-->
 <!--[if IE 7]> <html class="lt-ie9 lt-ie8" lang="en"> <![endif]-->
 <!--[if IE 8]> <html class="lt-ie9" lang="en"> <![endif]-->
 <!--[if gt IE 8]><!--> <html lang="en"> <!--<![endif]-->
 <head>
   <meta charset="utf-8">
   <meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1">
   <title>Start Claw-Machine</title>
   <link rel="stylesheet" href="css/style.css">
     <script src="https://js.stripe.com/v3/"></script>
   <!--[if lt IE 9]><script src="//html5shim.googlecode.com/svn/trunk/html5.js"></script><![endif]-->
 </head>
 <body>
   <div class="checkout">
     <div class="checkout-header">
       <h1 class="checkout-title">
         Betal
         <span class="checkout-price">Kr 3</span>
       </h1>
     </div>
         <center>
           <?php if ($game == false): ?>
             <h1>Oida!</h1>
             <p>Vi kan ikke starte spillet fordi <?php echo $errormsg; ?></p>
             <input onclick="location.href = 'https://claw.kolsrudweb.no/';" type="submit" value="KJØP EN SPILLKUPONG" class="checkout-btn">
           <?php elseif ($gameStarted == true): ?>
             <h1>Spillet er startet!</h1>
             <p>OBS! Det kan ta et par sekunder før maskinen reagerer. Du vil se at lyset slår seg på!</p>
             <input onclick="location.href = 'https://claw.kolsrudweb.no/';" type="submit" value="KJØP NYTT SPILL" class="checkout-btn">
             <i>TAKK!</i>
             <?php else: ?>
               <h1>Klar?</h1>
               <p>OBS! Spillet begynner med engang du klikker på knappen under. Les instrukser ved maskinen før du begynner!</p>
               <input onclick="location.href = 'https://claw.kolsrudweb.no/game.php?game=<?php echo $gameData["stripe"]; ?>&hash=<?php echo $gameData["hash"] ?>&action=start_game';" type="submit" value="START SPILL" class="checkout-btn">
               <i>OBS! Pass på at maskinen er ledig da dette ikke sjekkes av systemet. Startede spill refunderes IKKE.</i>
           <?php endif; ?>
         </center>
   </div>

   <div class="about">
     <p class="about-author">
       &copy; 2019 <a href="https://kolsrudweb.no" target="_blank">KolsrudWeb</a><br>
       INGEN REFUSJONER!
     </p>
   </div>
 </body>
 </html>
