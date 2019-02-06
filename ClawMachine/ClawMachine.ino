
#include <DFPlayer_Mini_Mp3.h>

#define x_left 37
#define x_right 23
#define y_forw 25
#define y_back 27
#define z_down 33
#define z_up 35
#define claw 29
#define claw2 42
#define bell 49
#define light0 22
#define light1 46
#define light2 48
#define grab_led 44

#define i_left	26
#define i_right	28
#define i_forward 30
#define i_backward 32
#define i_grab 50
#define i_coin 34
#define i_ls_xleft 52
#define i_ls_xright 47
#define i_ls_yforw 51
#define i_ls_yback 53
#define i_ls_zdown 38
#define i_ls_zup 40

#define game_length 20000
#define led_interval 250
#define audio_interval 180000
#define bell_length 200
#define grab_death_length 1000

#define music_idle 1
#define music_game 2
#define music_drop 3

//bool grab_led_state = false;
bool coin_state = false; //coin inserted
bool ready_state = false; //ready to start game
bool game_state = false; //game running
bool grab_state = false; //grabbed in current game
bool game_overtime = false; //ending by timer
bool claw_moved = false; //already Moved Claw

unsigned long current_time;

unsigned long game_start_time;
unsigned long led_last_time;
unsigned long audio_last_time;

unsigned char x, y, x_o, y_o; //0,1,2
bool x_s, y_s;

void loop() {
  current_time = millis();
  waiting();
  coin();
  play();
}

void setup() {
  pinMode(x_left, OUTPUT);
  pinMode(x_right, OUTPUT);
  pinMode(y_forw, OUTPUT);
  pinMode(y_back, OUTPUT);
  pinMode(z_down, OUTPUT);
  pinMode(z_up, OUTPUT);
  pinMode(claw, OUTPUT);
  pinMode(claw2, OUTPUT);
  pinMode(bell, OUTPUT);
  pinMode(light0, OUTPUT);
  pinMode(light1, OUTPUT);
  pinMode(light2, OUTPUT);
  pinMode(grab_led, OUTPUT);

  pinMode(i_left, INPUT);
  pinMode(i_right, INPUT);
  pinMode(i_forward, INPUT);
  pinMode(i_backward, INPUT);
  pinMode(i_grab, INPUT);
  pinMode(i_coin, INPUT);
  pinMode(i_ls_xleft, INPUT);
  pinMode(i_ls_xright, INPUT);
  pinMode(i_ls_yforw, INPUT);
  pinMode(i_ls_yback, INPUT);
  pinMode(i_ls_zdown, INPUT);
  pinMode(i_ls_zup, INPUT);

  Serial.begin(9600);
  Serial1.begin(9600);
  mp3_set_serial(Serial1);
  mp3_set_volume(25);
  mp3_DAC(true);
  
  digitalWrite(grab_led,true);
}
