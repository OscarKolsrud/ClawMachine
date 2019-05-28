<?php
error_reporting(0);
ini_set('display_errors', 0);
session_start();
require "assets/vendor/autoload.php";
// Set your secret key: remember to change this to your live secret key in production
// See your keys here: https://dashboard.stripe.com/account/apikeys
\Stripe\Stripe::setApiKey("sk_test_XXXXXXXXXXXXXXXXXXX");

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
  <?php if ($_GET["payment"] == "do"): ?>
    <?php
    $stripecheckout = \Stripe\Checkout\Session::create([
      'success_url' => 'https://claw.kolsrudweb.no/checkout_success.php',
      'cancel_url' => 'https://claw.kolsrudweb.no/index.php?error=cancel',
      'payment_method_types' => ['card'],
      'line_items' => [
        [
          'amount' => 300,
          'currency' => 'nok',
          'name' => '1 spill',
          'description' => '1 spill på claw machinen. BEMERK! Vennligst benytt en gyldig mail da det er her du får spillkupongen din!',
          'quantity' => 1,
        ],
      ]
    ]);

    $_SESSION["stripeID"] = $stripecheckout->id;
     ?>
     <script>
     var stripe = Stripe('pk_test_XXXXXXXXXXXXXXX');
     stripe.redirectToCheckout({
     sessionId: '<?php echo $stripecheckout->id; ?>'
     }).then(function (result) {
       // If `redirectToCheckout` fails due to a browser or network
       // error, display the localized error message to your customer
       // using `result.error.message`.
     });
     </script>
  <?php endif; ?>
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
    <?php
    if ($_GET["error"] == "cancel") {
      echo "<p><center>Du avbrøt kjøpet</center></p>";
    }
     ?>
    <p>
      <input onclick="location.href = 'https://claw.kolsrudweb.no?payment=do';" type="submit" value="Gjennomfør kjøp" class="checkout-btn">
    </p>
  </div>

  <div class="about">
    <p class="about-author">
      &copy; 2019 <a href="https://kolsrudweb.no" target="_blank">KolsrudWeb</a><br>
      INGEN REFUSJONER!
    </p>
  </div>
</body>
</html>
