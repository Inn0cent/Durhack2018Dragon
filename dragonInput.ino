const int buttonIncr = 4;
const int buttonDecr = 5;

void setup() {
    pinMode(buttonIncr, INPUT);
    pinMode(buttonDecr, INPUT);
    Serial.begin(115200);
    Serial.println("waiting");
}

void loop() {
    int pressedIncr = digitalRead(buttonIncr);
	int pressedDecr = digitalRead(buttonDecr);
    if (pressedIncr == 1) {
        Serial.println("increment");
    }
	
	if (pressedDecr == 1) {
		Serial.println("decrement");
	}
}