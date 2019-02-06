void idle() {
  if (digitalRead(i_ls_xleft)) {
    x = 2;
  } else if (digitalRead(i_ls_xright)) {
    x = 0;
  }
  if (digitalRead(i_ls_yforw)) {
    y = 2;
  } else if (digitalRead(i_ls_yback)) {
    y = 0;
  }

  x_s = true;

  y_s = true;
  if (x_s) {
    switch (x) {
      case 0:
        digitalWrite(x_right, false);
        digitalWrite(x_left, true);
        break;
      case 2:
        digitalWrite(x_left, false);
        digitalWrite(x_right, true);
        break;
    }
    x_s = false;
  }
  if (y_s) {
    switch (y) {
      case 0:
        digitalWrite(y_forw, false);
        digitalWrite(y_back, true);
        break;
      case 2:
        digitalWrite(y_back, false);
        digitalWrite(y_forw, true);
        break;
    }
    y_s = false;
  }
}
