void play() {
  if (coin_state && !game_state && ready_state) {
    if (digitalRead(i_grab)) {
      Serial.println("start Game");
      digitalWrite(grab_led, true);
      grab_state = false;
      claw_moved = false;
      //delay(2);
      mp3_stop();
      mp3_stop();
      //delay(2);
      mp3_play(music_game);
      mp3_play(music_game);
      //delay(4);
      game_start_time = current_time;
      game_state = true;
      x_s = y_s = false;
      digitalWrite(grab_led, false);
    }
    return;
  }
  if (game_state && !grab_state) {
    if (digitalRead(i_left)) {
      delay(10);
      x = 0;
    } else if (digitalRead(i_right)) {
      delay(10);
      x = 2;
    } else {
      delay(10);
      x = 1;
    }
    if (digitalRead(i_backward)) {
      delay(10);
      y = 0;
    } else if (digitalRead(i_forward)) {
      delay(10);
      y = 2;
    } else {
      delay(10);
      y = 1;
    }
    if (x_o != x)
      x_s = true;
    if (y_o != y)
      y_s = true;

    if (claw_moved && digitalRead(i_grab) && game_start_time + grab_death_length <= current_time) {
      grab_state = true;
      digitalWrite(grab_led, true);
    }
    if (game_start_time + game_length <= current_time) {
      grab_state = true;
      game_overtime = true;
      digitalWrite(grab_led, true);
      delay(4);
      mp3_stop();
    }

    if ( (digitalRead(i_ls_xleft)&&x==0) || (digitalRead(i_ls_xright)&&x==2) || grab_state) {
      digitalWrite(x_left, false);
      digitalWrite(x_right, false);
      x_s = false;
    }
    if ((digitalRead(i_ls_yforw)&&y==2) || (digitalRead(i_ls_yback)&&y==0) || grab_state) {
      digitalWrite(y_forw, false);
      digitalWrite(y_back, false);
      y_s = false;
    }
    if (x_s) {
      switch (x) {
        case 0:
          digitalWrite(x_right, false);
          digitalWrite(x_left, true);
	  claw_moved = true;
          break;
        case 1:
          digitalWrite(x_right, false);
          digitalWrite(x_left, false);
          break;
        case 2:
          digitalWrite(x_left, false);
          digitalWrite(x_right, true);
	  claw_moved = true;
          break;
      }
      x_o = x;
      x_s = false;
    }
    if (y_s) {
      switch (y) {
        case 0:
          digitalWrite(y_forw, false);
          digitalWrite(y_back, true);
	  claw_moved = true;
          break;
        case 1:
          digitalWrite(y_forw, false);
          digitalWrite(y_back, false);
          break;
        case 2:
          digitalWrite(y_back, false);
          digitalWrite(y_forw, true);
	  claw_moved = true;
          break;
      }
      y_o = y;
      y_s = false;
    }
  }
  if (grab_state && game_overtime) {
    Serial.println("Bell");
    digitalWrite(bell, true);
    delay(bell_length);
    digitalWrite(bell, false);
  }

  if (grab_state) {
    delay(100);
    mp3_stop();
    mp3_stop();
    //delay(4);
    mp3_play(music_drop);
    mp3_play(music_drop);
    //delay(4);
    digitalWrite(claw2, false); //open claw
    digitalWrite(claw, false);
    digitalWrite(light0, true); //turn lights on
    digitalWrite(z_up, false); //let claw down till i_ls_zdown
    digitalWrite(z_down, true);
    Serial.println("Claw going Down");
    while (!digitalRead(i_ls_zdown)) {
      delay(1);
    }
    digitalWrite(z_down, false); //stop wait 1s
    Serial.println("Claw Down");
    delay(100);
    digitalWrite(claw, true); //close claw wait 0.1s
    delay(100);
    Serial.println("Claw going Up");
    digitalWrite(z_up, true); //let claw up till i_ls_zup
    delay(100);
    //delay(250); //wait
    //digitalWrite(claw2, false); //switch back claws
    //digitalWrite(claw, true);
    
    while (!digitalRead(i_ls_zup)) {
      delay(10);
    }
    //random(x)==y probability for: Switch claws
    if (!(int)random(2)==1)
{
    delay(10);
    digitalWrite(claw, false); //switch claws
    digitalWrite(claw2, true);
}

    Serial.println("Claw Up; Going LEFT FORWARD");
    digitalWrite(z_up, false); //stop wait 1.5s
    digitalWrite(x_left, true); //move to left front till both reached
    delay(10);
    digitalWrite(y_forw, true);
    delay(10);
    while (!digitalRead(i_ls_xleft) || !digitalRead(i_ls_yforw)) {
      if (digitalRead(i_ls_xleft) && digitalRead(x_left))
        digitalWrite(x_left, false);    //savety Kill
      if (digitalRead(i_ls_yforw) && digitalRead(y_forw))
        digitalWrite(y_forw, false);    //savety Kill
      delay(10);
    }
    Serial.println("On End Position");
    digitalWrite(x_left, false);  //stop both wait 0.1s
    digitalWrite(y_forw, false);

    digitalWrite(z_down, true); //Claw goes down for 1 sec
    delay(1000);
    digitalWrite(z_down, false);
    
    digitalWrite(bell, true); //bell rings 2 times
    delay(200);
    digitalWrite(bell, false);
    delay(200);
    digitalWrite(bell, true);
    delay(200);
    digitalWrite(bell, false);
    delay(100); //Claw open delay 600+500
    Serial.println("OpenClaws");
    digitalWrite(claw, false);  //open both claws bell for .5s
    digitalWrite(claw2, false);

    digitalWrite(z_up, true); //Claw going up again till i_ls_zup
    while (!digitalRead(i_ls_zup)) {
      delay(10);
    }
    digitalWrite(z_up, false);

    delay(500); //safety delay

    digitalWrite(grab_led,true);
    delay(2);
    //coin_state = false; //reset vars
    grab_state = false;
    game_state = false;
    ready_state = false;
    coin_state = false;
    digitalRead(i_coin);
    digitalRead(i_grab);
    audio_last_time = millis();
    return;
  }
}
