const int displayPins[7] = {7, 8, 9, 10, 11, 12, 13};

//byte show[7] = {1,1,0,0,1,1,1};

byte show[10][7] = 
{
  {0,1,1,1,1,1,1},  // 0
  {0,1,0,0,0,0,1},  // 1
  {1,0,1,1,0,1,1},  // 2
  {1,1,1,0,0,1,1},  // 3
  {1,1,0,0,1,0,1},  // 4
  {1,1,1,0,1,1,0},  // 5
  {1,1,1,1,1,1,0},  // 6
  {0,1,0,0,0,1,1},  // 7
  {1,1,1,1,1,1,1},  // 8
  {1,1,0,0,1,1,1}   // 9
};
byte conVal = true;

void setup() 
{
  // put your setup code here, to run once:
  for (int i = 0; i < 7; i++)
  {
    pinMode(displayPins[i], OUTPUT);
  }
}

void loop() 
{
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 7; j++)
    {
      if (show[i][j] == 1)
      {
        conVal =  LOW;
      }
      else
      {
        conVal = HIGH;
      }
      digitalWrite(displayPins[j], conVal);
    }
    delay(1000);
  }/*
  for (int i = 0; i < 7; i++)
  {
    
      if (show[i] == 1)
      {
        conVal =  LOW;
      }
      else
      {
        conVal = HIGH;
      }
      digitalWrite(displayPins[i], conVal);
  }*/
  
}
