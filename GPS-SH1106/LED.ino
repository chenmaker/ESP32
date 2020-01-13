void LED(){
    if(gps.speed.kmph()>=90){
    digitalWrite(led[0], HIGH);
    }else if(gps.speed.kmph()>=80){
    digitalWrite(led[0], LOW);
    digitalWrite(led[1], HIGH);
    }else if(gps.speed.kmph()>=60){
    digitalWrite(led[0], LOW);
    digitalWrite(led[1], LOW);
    digitalWrite(led[2], HIGH);
    }else if(gps.speed.kmph()>=40){
    digitalWrite(led[0], LOW);
    digitalWrite(led[1], LOW);
    digitalWrite(led[2], LOW);
    digitalWrite(led[3], HIGH);
    }else if(gps.speed.kmph()>=20){
    digitalWrite(led[0], LOW);
    digitalWrite(led[1], LOW);
    digitalWrite(led[2], LOW);
    digitalWrite(led[3], LOW);
    digitalWrite(led[4], HIGH);
    }
  }
