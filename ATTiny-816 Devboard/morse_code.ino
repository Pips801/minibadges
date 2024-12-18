// This code was written by ChatGPT 4o mini

// Adjust these timings as you like
const unsigned int DOT_DURATION = 200;    // Duration of a dot
const unsigned int DASH_DURATION = 800;   // Duration of a dash (4 * DOT_DURATION)
const unsigned int INTRA_CHAR_DELAY = 200;  // Between elements of a single letter
const unsigned int LETTER_SPACE = 800;    // Between letters (4 * DOT_DURATION)
const unsigned int WORD_SPACE = 1400;     // Between words (7 * DOT_DURATION)

// Map PB2 to an Arduino pin number (depends on your core and board).
// For MegaTinyCore, consult the pinout. This is just an example.
// Replace "LED_PIN" with the Arduino pin number that corresponds to PB2.
const int LED_PIN = PIN_PB2; // Example: If pin 2 maps to PB2, adjust if needed.

// Morse code dictionary for A-Z and 0-9.
// Use '.' for dot and '-' for dash.
struct MorseMapping {
  char character;
  const char *morse;
};

MorseMapping morseTable[] = {
  {'A', ".-"},   {'B', "-..."}, {'C', "-.-."}, {'D', "-.."},  {'E', "."},    {'F', "..-."},
  {'G', "--."},  {'H', "...."}, {'I', ".."},   {'J', ".---"}, {'K', "-.-"},  {'L', ".-.."},
  {'M', "--"},   {'N', "-."},   {'O', "---"},  {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."},
  {'S', "..."},  {'T', "-"},    {'U', "..-"},  {'V', "...-"}, {'W', ".--"},  {'X', "-..-"},
  {'Y', "-.--"}, {'Z', "--.."}, 
  {'0', "-----"},{'1', ".----"},{'2', "..---"},{'3', "...--"},{'4', "....-"},
  {'5', "....."},{'6', "-...."},{'7', "--..."},{'8', "---.."},{'9', "----."}
};

const int MORSE_TABLE_SIZE = sizeof(morseTable) / sizeof(MorseMapping);

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  
}

void loop() {
  char message[] = "PIPS WAS HERE";
  sendMorseMessage(message);
}

// Look up the Morse code sequence for a given character
const char* charToMorse(char c) {
  // Convert character to uppercase to match our table
  c = toupper((unsigned char)c);
  
  for (int i = 0; i < MORSE_TABLE_SIZE; i++) {
    if (morseTable[i].character == c) {
      return morseTable[i].morse;
    }
  }
  
  // If not found (like space or punctuation), return NULL
  return NULL;
}

void sendMorseMessage(char* message) {
  // Iterate through each character in the message
  int i = 0;
  while (message[i] != '\0') {
    char c = message[i];
    // Check if it's a space
    if (c == ' ') {
      // Word space
      delay(WORD_SPACE);
      i++;
      continue;
    }

    // Convert character to Morse
    const char* morseCode = charToMorse(c);
    if (morseCode != NULL) {
      // Send this character's Morse code
      sendMorseCharacter(morseCode);
      // Delay between letters
      delay(LETTER_SPACE);
    }
    i++;
  }
}

// Send a single Morse code character (e.g. ".-")
void sendMorseCharacter(const char* morseCode) {
  // Each dot or dash is turned on and off
  for (int j = 0; morseCode[j] != '\0'; j++) {
    if (morseCode[j] == '.') {
      // Dot
      digitalWrite(LED_PIN, HIGH);
      delay(DOT_DURATION);
      digitalWrite(LED_PIN, LOW);
    } else if (morseCode[j] == '-') {
      // Dash
      digitalWrite(LED_PIN, HIGH);
      delay(DASH_DURATION);
      digitalWrite(LED_PIN, LOW);
    }
    // Delay between parts of the same letter
    if (morseCode[j+1] != '\0') {
      delay(INTRA_CHAR_DELAY);
    }
  }
}
