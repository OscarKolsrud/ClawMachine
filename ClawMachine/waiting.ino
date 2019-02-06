void waiting() {
  if (!coin_state && !game_state) {
    if (audio_last_time + audio_interval <= current_time) {
      Serial.println("Idle");
      audio_last_time = current_time;
      mp3_play(music_idle);
    }
    //idle();
  }
}
