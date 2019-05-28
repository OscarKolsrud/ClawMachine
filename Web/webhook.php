<?php
require "assets/vendor/autoload.php";
// Set your secret key: remember to change this to your live secret key in production
// See your keys here: https://dashboard.stripe.com/account/apikeys
$mysqli = new mysqli("localhost","kolsrudw_claw","PASSORD","kolsrudw_claw_machine") or die($mysqli->error);
$mysqli->set_charset("utf8mb4");

\Stripe\Stripe::setApiKey("sk_test_XXXXXXXXXXXXXXXXXXXX");

function randHash($len=32)
{
	return substr(md5(openssl_random_pseudo_bytes(20)),-$len);
}

// You can find your endpoint's secret in your webhook settings
$endpoint_secret = 'whsec_XXXXXXXXXXXXXXXXXXXX';

$payload = @file_get_contents('php://input');
$sig_header = $_SERVER['HTTP_STRIPE_SIGNATURE'];
$event = null;

try {
    $event = \Stripe\Webhook::constructEvent(
        $payload, $sig_header, $endpoint_secret
    );
} catch(\UnexpectedValueException $e) {
    // Invalid payload
    http_response_code(400); // PHP 5.4 or greater
    exit();
} catch(\Stripe\Error\SignatureVerification $e) {
    // Invalid signature
    http_response_code(400); // PHP 5.4 or greater
    exit();
}

// Handle the checkout.session.completed event
if ($event->type == 'checkout.session.completed') {
    $session = $event->data->object->id;
    $customer = $event->data->object->customer;
    $chargeID = $event->data->object->payment_intent;

    $customerdata = \Stripe\Customer::retrieve($customer);
    $email = $customerdata->email;
    $hash = randHash(50);
    $url = "https://claw.kolsrudweb.no/game.php?game=$session&hash=$hash";

    $query = "INSERT INTO `games` (`stripe`, `email`, `hash`, `charge_id`) VALUES ('$session', '$email', '$hash', '$chargeID')";
    if ($mysqli->query($query) === TRUE) {
      $curl = curl_init();

      curl_setopt_array($curl, array(
        CURLOPT_URL => "https://api.sendgrid.com/v3/mail/send",
        CURLOPT_RETURNTRANSFER => true,
        CURLOPT_ENCODING => "",
        CURLOPT_MAXREDIRS => 10,
        CURLOPT_TIMEOUT => 30,
        CURLOPT_HTTP_VERSION => CURL_HTTP_VERSION_1_1,
        CURLOPT_CUSTOMREQUEST => "POST",
        CURLOPT_POSTFIELDS => "{\n    \"from\": {\n        \"email\": \"claw-machine-noreply@kolsrudweb.no\"\n    },\n    \"personalizations\": [\n        {\n            \"to\": [\n                {\n                    \"email\": \"$email\"\n                }\n            ],\n            \"dynamic_template_data\": {\n                \"url\": \"$url\"\n            }\n        }\n    ],\n    \"template_id\": \"d-b4216b24ad9a4580b5baa3a537585f9b\"\n}",
        CURLOPT_HTTPHEADER => array(
          "Authorization: Bearer XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
          "Content-Type: application/json",
          "cache-control: no-cache"
        ),
      ));

      $response = curl_exec($curl);
      $err = curl_error($curl);

      curl_close($curl);

      http_response_code(200); // PHP 5.4 or greater
    } else {
      http_response_code(401); // PHP 5.4 or greater
    }
}
