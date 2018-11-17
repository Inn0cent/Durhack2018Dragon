const int buttonIncr = 4;
const int buttonDecr = 5;

int pressedIncr;
int pressedDecr;
int lastIncr;
int lastDecr;

void setup() {
    pinMode(buttonIncr, INPUT);
    pinMode(buttonDecr, INPUT);
    Serial.begin(115200);
    Serial.println("waiting");
}

void loop() {
    pressedIncr = digitalRead(buttonIncr);
	pressedDecr = digitalRead(buttonDecr);
	
	// compare the buttonState to its previous state
	if (pressedIncr != lastIncr) {
		// if the state has changed, increment the counter
		if (pressedIncr == HIGH) {
			// if the current state is HIGH then the button went from off to on:
			Serial.println("increment");
		}
		// Delay a little bit to avoid bouncing
		delay(50);
	}
	// save the current state as the last state, for next time through the loop
	lastIncr = pressedIncr;
	
	// compare the buttonState to its previous state
	if (pressedDecr != lastDecr) {
		// if the state has changed, increment the counter
		if (pressedDecr == HIGH) {
			// if the current state is HIGH then the button went from off to on:
			Serial.println("decrement");
		}
		// Delay a little bit to avoid bouncing
		delay(50);
	}
	// save the current state as the last state, for next time through the loop
	lastDecr = pressedDecr;
	
}