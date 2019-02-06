void coin() {
  if (!coin_state && digitalRead(i_coin) && !game_state) {
    coin_state = true;
    game_state = false;
    game_overtime = false;
    ready_state = false;
    grab_state = false;
    Serial.println("Coin Inserted");
  }
  if (coin_state && !ready_state && !game_state) {
    x = y = x_o = y_o = 1;
    x_s = y_s = false;
    digitalWrite(x_left, false);
    digitalWrite(x_right, false);
    digitalWrite(y_forw, false);
    digitalWrite(y_back, false);
    ready_state = true;
    Serial.println("Ready");
  }
  if (coin_state && !game_state) {
    if (led_last_time + led_interval <= current_time) {
      led_last_time = current_time;
      digitalWrite(grab_led, !digitalRead(grab_led));
    }
  }
}
