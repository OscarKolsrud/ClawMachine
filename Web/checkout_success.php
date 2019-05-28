<?php
error_reporting(0);
ini_set('display_errors', 0);
session_start();
require "assets/vendor/autoload.php";
$checkoutsession = $_SESSION["stripeID"];

$mysqli = new mysqli("localhost","kolsrudw_claw","PASSORD","kolsrudw_claw_machine") or die($mysqli->error);
$mysqli->set_charset("utf8mb4");

$ensure = $mysqli->query("SELECT * FROM games WHERE stripe='$checkoutsession'") or die($mysqli->error);

if ($ensure->num_rows == 1) {
  $gameData = $ensure->fetch_assoc();
  $game = true;
} else {
  $game = false;
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
   <?php if ($game == false): ?>
     <meta http-equiv="refresh" content="3; URL=https://claw.kolsrudweb.no/checkout_success.php">
   <?php endif; ?>
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
             <h1>Takk!</h1>
             <p>Vennligs vent mens vi bekrefter betalingen din! (Siden vil laste på nytt flere ganger)</p>
             <i>PS! Du vil også motta spillkupongen på e-posten du oppgae.</i>
             <?php else: ?>
               <h1>Takk!</h1>
               <p>Betalingen din er <b>BEKREFTET</b> bruk knappen under for å gå til spillet!</p>
               <input onclick="location.href = 'https://claw.kolsrudweb.no/game.php?game=<?php echo $gameData["stripe"]; ?>&hash=<?php echo $gameData["hash"] ?>';" type="submit" value="Gå til spillkupongen" class="checkout-btn">
               <i>PS! Du vil også motta spillkupongen på e-posten du oppga.</i>
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
