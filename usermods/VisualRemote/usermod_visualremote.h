#pragma once

#include "wled.h"

// Define the necessary constants
#define NIGHT_MODE_DEACTIVATED     -1
#define NIGHT_MODE_BRIGHTNESS      5

// Button Mappings


// Unique integers for each button press type
#define WIZMOTE_BUTTON_OFF_SHORT        1
#define WIZMOTE_BUTTON_OFF_DOUBLE       2
#define WIZMOTE_BUTTON_OFF_TRIPLE       3
#define WIZMOTE_BUTTON_OFF_QUADRUPLE    4
#define WIZMOTE_BUTTON_OFF_QUINTUPLE    5
#define WIZMOTE_BUTTON_OFF_SEXTUPLE     6
#define WIZMOTE_BUTTON_OFF_LONG         7

#define WIZMOTE_BUTTON_ON_SHORT         8
#define WIZMOTE_BUTTON_ON_DOUBLE        9
#define WIZMOTE_BUTTON_ON_TRIPLE        10
#define WIZMOTE_BUTTON_ON_QUADRUPLE     11
#define WIZMOTE_BUTTON_ON_QUINTUPLE     12
#define WIZMOTE_BUTTON_ON_SEXTUPLE      13
#define WIZMOTE_BUTTON_ON_LONG          14

#define WIZMOTE_BUTTON_TWO_SHORT        15
#define WIZMOTE_BUTTON_TWO_DOUBLE       16
#define WIZMOTE_BUTTON_TWO_TRIPLE       17
#define WIZMOTE_BUTTON_TWO_QUADRUPLE    18
#define WIZMOTE_BUTTON_TWO_QUINTUPLE    19
#define WIZMOTE_BUTTON_TWO_SEXTUPLE     20
#define WIZMOTE_BUTTON_TWO_LONG         21

#define WIZMOTE_BUTTON_ONE_SHORT        22
#define WIZMOTE_BUTTON_ONE_DOUBLE       23
#define WIZMOTE_BUTTON_ONE_TRIPLE       24
#define WIZMOTE_BUTTON_ONE_QUADRUPLE    25
#define WIZMOTE_BUTTON_ONE_QUINTUPLE    26
#define WIZMOTE_BUTTON_ONE_SEXTUPLE     27
#define WIZMOTE_BUTTON_ONE_LONG         28

#define WIZMOTE_BUTTON_THREE_SHORT      36
#define WIZMOTE_BUTTON_THREE_DOUBLE     37
#define WIZMOTE_BUTTON_THREE_TRIPLE     38
#define WIZMOTE_BUTTON_THREE_QUADRUPLE  39
#define WIZMOTE_BUTTON_THREE_QUINTUPLE  40
#define WIZMOTE_BUTTON_THREE_SEXTUPLE   41
#define WIZMOTE_BUTTON_THREE_LONG       42

#define WIZMOTE_BUTTON_FOUR_SHORT       29
#define WIZMOTE_BUTTON_FOUR_DOUBLE      30
#define WIZMOTE_BUTTON_FOUR_TRIPLE      31
#define WIZMOTE_BUTTON_FOUR_QUADRUPLE   32
#define WIZMOTE_BUTTON_FOUR_QUINTUPLE   33
#define WIZMOTE_BUTTON_FOUR_SEXTUPLE    34
#define WIZMOTE_BUTTON_FOUR_LONG        35

#define WIZMOTE_BUTTON_BRIGHT_UP_SHORT       43
#define WIZMOTE_BUTTON_BRIGHT_UP_DOUBLE      44
#define WIZMOTE_BUTTON_BRIGHT_UP_TRIPLE      45
#define WIZMOTE_BUTTON_BRIGHT_UP_QUADRUPLE   46
#define WIZMOTE_BUTTON_BRIGHT_UP_QUINTUPLE   47
#define WIZMOTE_BUTTON_BRIGHT_UP_SEXTUPLE    48
#define WIZMOTE_BUTTON_BRIGHT_UP_LONG        49

#define WIZMOTE_BUTTON_BRIGHT_DOWN_SHORT     50
#define WIZMOTE_BUTTON_BRIGHT_DOWN_DOUBLE    51
#define WIZMOTE_BUTTON_BRIGHT_DOWN_TRIPLE    52
#define WIZMOTE_BUTTON_BRIGHT_DOWN_QUADRUPLE 53
#define WIZMOTE_BUTTON_BRIGHT_DOWN_QUINTUPLE 54
#define WIZMOTE_BUTTON_BRIGHT_DOWN_SEXTUPLE  55
#define WIZMOTE_BUTTON_BRIGHT_DOWN_LONG      56

#define WIZMOTE_BUTTON_NIGHT_SHORT      57
#define WIZMOTE_BUTTON_NIGHT_DOUBLE     58
#define WIZMOTE_BUTTON_NIGHT_TRIPLE     59
#define WIZMOTE_BUTTON_NIGHT_QUADRUPLE  60
#define WIZMOTE_BUTTON_NIGHT_QUINTUPLE  61
#define WIZMOTE_BUTTON_NIGHT_SEXTUPLE   62
#define WIZMOTE_BUTTON_NIGHT_LONG       63

#define WIZMOTE_BUTTON_PROGRAM          255

const int LETTER_WIDTH = 6;   // 6Width of each character
const int LETTER_HEIGHT = 8;  // 8Height of each character

// Define the WizMoteMessageStructure
typedef struct WizMoteMessageStructure {
  uint8_t program;
  uint8_t seq[4];
  uint8_t dt1;
  uint8_t button;
  uint8_t dt2;
  uint8_t batLevel;
  uint8_t byte10;
  uint8_t byte11;
  uint8_t byte12;
  uint8_t byte13;
} message_structure_t;

// Declare static variables
static volatile byte presetToApply = 0;
static uint32_t last_seq_visualremote = UINT32_MAX;
static int brightnessBeforeNightMode_visualremote = NIGHT_MODE_DEACTIVATED;
static int NextBrightnessStep = 3;
static bool SyncMode = true;
static bool SyncModeChanged = false;
static bool menuActive = false;
static bool ButtonPressed = false;
static uint8_t MenuChoiceStart = 30;
static uint8_t MagicFlowMode = 0;
static uint8_t MagicFlowProgram = 0;
static bool BroadcastProgram = false;
static bool UpdateBrightness = false;
uint8_t brightnessrepeat = 2;
uint8_t repeat = 10;

// Declare sequenceNumber as a global variable
uint32_t sequenceNumber = 0;

uint32_t nextSequenceNumber() {
  // Increment sequence number
  sequenceNumber++;

  // Return the new sequence number
  return sequenceNumber;
}

// Toggle menu when OFF is long-pressed
inline void toggleMenu_visualremote() {
  menuActive = !menuActive;
  
  Serial.print("Menu toggled :");
  Serial.println(menuActive);
}


const byte wifi_icon[16][16] PROGMEM = {
    {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
    {0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0},
    {0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0},
    {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1},
    {1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1},
    {1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1},
    {0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
    {0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
    {0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0},
    {1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1},
    {1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1},
    {0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0},
    {0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0},
    {0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0},
    {0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0}
};
const byte access_point_icon[16][16] PROGMEM = {
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
  {0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0},
  {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0},
  {0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0},
  {0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0},
  {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0},
  {0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0},
  {0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

static const byte brightnessSteps_visualremote[] = {
  6, 33, 50, 128 
};


static const size_t numBrightnessSteps_visualremote = sizeof(brightnessSteps_visualremote) / sizeof(byte);


inline void applyBrightness_visualremote() {
  brightnessrepeat--;
  if (brightnessrepeat <= 0)
  {
    UpdateBrightness = false;
  }
  bri = brightnessSteps_visualremote[NextBrightnessStep]; 
 // DEBUG_PRINTF("Brightness set: %u\n", bri);
 // DEBUG_PRINTF("Brightness step: %u\n", NextBrightnessStep);
  stateUpdated(CALL_MODE_BUTTON);
}

inline void setBrightness_visualremote() {    
  NextBrightnessStep++;
  if (NextBrightnessStep >= sizeof(brightnessSteps_visualremote)) {
    NextBrightnessStep = 0;
  }
  applyBrightness_visualremote();
}

inline void resetBrightness_visualremote() {    
  NextBrightnessStep = sizeof(brightnessSteps_visualremote) - 1;
  applyBrightness_visualremote();
}



inline void broadcastProgram() {
  repeat = 10;
  BroadcastProgram = true;
}


inline void togglePower_visualremote() {
  //resetNightMode_visualremote();
  toggleOnOff();
  stateUpdated(CALL_MODE_BUTTON);
}

inline void toggleSyncMode_visualremote() {  
  SyncMode = !SyncMode;
  SyncModeChanged = true;
}


inline void increaseSpeed()
{
  DEBUG_PRINTF("Increase speed: %u\n", effectSpeed);
  effectSpeed = min(effectSpeed + 20, 255);
  stateChanged = true;
  for (unsigned i=0; i<strip.getSegmentsNum(); i++) {
      Segment& seg = strip.getSegment(i);
      if (!seg.isActive()) continue;
      seg.speed = effectSpeed;
  }
  colorUpdated(CALL_MODE_FX_CHANGED);
}



void magic_flow(uint8_t program) {
  Serial.printf("Magic Flow: %u\n", MagicFlowMode);
  MagicFlowProgram = program;
  if (MagicFlowMode == 0) 
  {
    MagicFlowMode = 1;
    presetToApply = 11;  
    applyPreset(presetToApply, CALL_MODE_BUTTON_PRESET);   
    return;
  }
  if (MagicFlowMode == 1) 
  {
    MagicFlowMode = 2;
    presetToApply = 12;  
    applyPreset(presetToApply, CALL_MODE_BUTTON_PRESET);   
    return;
  }
  if (MagicFlowMode == 2) 
  {
    MagicFlowMode = 3;
    presetToApply = 13;  
    applyPreset(presetToApply, CALL_MODE_BUTTON_PRESET);   

    return;
  }
  if (MagicFlowMode == 3) 
  {
    MagicFlowMode = 0;
    presetToApply = MagicFlowProgram;  
    applyPreset(presetToApply, CALL_MODE_BUTTON_PRESET);   
    return;
  }

}



inline void applyPreset_visualremote(uint8_t presetID) {
  if (MagicFlowMode > 0) 
  {
    magic_flow(MagicFlowProgram);
    return;
  }
  if (presetToApply == presetID) {
    if (presetID == 2)
    {
      FeedFish();
      return;;
    }
    if (presetID == 4)
    {
      increaseSpeed();
    }
    return;
  };
  presetToApply = presetID;  
  applyPreset(presetID, CALL_MODE_BUTTON_PRESET);    
  brightnessrepeat = 2;
  UpdateBrightness = true;
}

inline void applyPreset3_visualremote(uint8_t presetID) {
  if (presetToApply == 3)
  {
    applyPreset_visualremote(8);
    return;
  }
  if (presetToApply == 8)
  {
    applyPreset_visualremote(9);
    return;
  }
  applyPreset_visualremote(3);
}

inline void enableAP_visualremote() {
  if (WiFi.status() == WL_CONNECTED) {
    return;
  }
  if (!apActive) WLED::instance().initAP();       // instantly go to ap mode
  Serial.println("Enabling Access Point");  
}
static char savedClientSSID[33]; 

inline void initWifi() {
  Serial.println("Enabling WiFi");
  wifiEnabled = true;
}

struct Pattern {
  uint8_t id;           // ID of the pattern
  String name;          // Name of the pattern
  uint8_t length;       // Actual length of the pattern
  String colors[12];    // Up to 12 colors in HEX string format
};

unsigned long lastTime = 0;


// Usermod class
class UsermodVisualRemote : public Usermod {
  private:
    bool enabled = false;
    static const char _name[];
    static const char _enabled[];
    int segmentId;
    int segmentPixelOffset;
    int timeOutMenu;
    String presetNames[255]; 
    bool preset_available[255] = {false};
    Pattern patterns[255]; // Array to hold patterns for each preset
    bool isDisplayingEffectIndicator = false;

    uint8_t currentEffectIndex = MenuChoiceStart;
    unsigned long lastTime = 0;

    Pattern* getPatternById(uint8_t id) {
      for (int i = 0; i < 255; i++) {
        if (patterns[i].id == id) {
          return &patterns[i];
        }
      }
      return nullptr; // Return nullptr if no matching pattern is found
    }

    // Menu variables
    uint8_t menuIndex = 0; // 0: WiFi, 1: AP, 2: Sync
    long scrollOffset = 0;
    unsigned long lastScrollTime = 0;
    const int scrollSpeed = 100; // milliseconds between scroll steps

 

    // Function to handle scrolling the text
    void scrollText(Segment& segment, String text, int x, int y, CRGB color) {
      int textWidth = text.length() * (LETTER_WIDTH + 1); // Add 1 for space
      int startX = segment.width(); // Start off-screen to the right

      for (int i = 0; i < segment.width(); ++i) {
        int charIndex = (i + scrollOffset) / (LETTER_WIDTH + 1); // Use LETTER_WIDTH + 1
        if (charIndex >= 0 && charIndex < text.length()) {
          int charX = startX - scrollOffset + i;
          segment.drawCharacter(text[charIndex], charX, y, LETTER_WIDTH, LETTER_HEIGHT, color);
        }
      }

      // Update scroll offset for the next frame
      scrollOffset++;
      if (scrollOffset > textWidth + startX) {
        scrollOffset = 0; // Reset scroll
      }
    }

    // Function to handle menu item toggling
    void toggleMenuItem() {
      lastTime = millis();
      switch (menuIndex) {
        case 0: // WiFi
          wifiEnabled = !wifiEnabled;       
          SyncModeChanged = true;        
            
          Serial.println("Toggling WiFi ");
          break;
        case 1: // AP
          // Toggle AP state
          apActive = !apActive;
          SyncModeChanged = true;
          if (apActive) {            
            WLED::instance().initAP();
          } else {
            WiFi.softAPdisconnect(true);
            WiFi.mode(WIFI_STA);
          }
          Serial.println("Toggling AP");
          break;
        case 2: // Sync
          // Toggle Sync state
          SyncMode = !SyncMode;
          SyncModeChanged = true;
          Serial.println("Toggling Sync");
          break;
      }
    }

  public:
  void setup() {
    Serial.println("VisualRemote mod active!");
    //strncpy(savedClientSSID, multiWiFi[0].clientSSID, 32);     
    //multiWiFi[0].clientSSID[0] = '\0';
    apActive = false;
   //apBehavior = AP_BEHAVIOR_BUTTON_ONLY;
    //WiFi.mode(WIFI_MODE_NULL);
    
    for (unsigned presetIndex = 1; presetIndex < 50; presetIndex++)
    {
      String name = "";
      preset_available[presetIndex] = getPresetName(presetIndex, name);
      Serial.printf("Preset Index: %u, Name: %s\n", presetIndex, name.c_str());       
    }
  }
    void addToConfig(JsonObject& root) override {
      JsonObject top = root.createNestedObject(FPSTR(_name));
      top[FPSTR(_enabled)] = enabled;
      top["SegmentId"] = segmentId;
      top["SegmentPixelOffset"] = segmentPixelOffset;
      top["TimeOutMenu"] = timeOutMenu;     
      top["MagicFlowStart"] = MenuChoiceStart;     
    }

    bool readFromConfig(JsonObject& root) override {
      JsonObject top = root[FPSTR(_name)];

      bool configComplete = !top.isNull();

      configComplete &= getJsonValue(top[FPSTR(_enabled)], enabled);
      configComplete &= getJsonValue(top["SegmentId"], segmentId, 1);  
      configComplete &= getJsonValue(top["SegmentPixelOffset"], segmentPixelOffset, 0);  
      configComplete &= getJsonValue(top["TimeOutMenu"], timeOutMenu, 300);  
      configComplete &= getJsonValue(top["MagicFlowStart"], MenuChoiceStart, 11);          

      return configComplete;
    }


   void onButtonUpPress() {
      if (menuActive) {
        menuIndex = (menuIndex + 1) % 2; // Cycle through 0, 1
        scrollOffset = 0; // Reset scroll when changing menu items
        return;
      }
      if (MagicFlowMode > 0) 
      {
        magic_flow(MagicFlowProgram);
      } else {
        do {
          currentEffectIndex++;
      
          if (currentEffectIndex >= 255) {
            currentEffectIndex = MenuChoiceStart;
          }
          DEBUG_PRINTF("> Up effect %d %d \n", currentEffectIndex, MenuChoiceStart);
          DEBUG_PRINTF("preset_available[%u] = %s\n", currentEffectIndex, preset_available[currentEffectIndex] ? "true" : "false");

        } while (!preset_available[currentEffectIndex]);
        DEBUG_PRINTF("> Start Display effect %d \n", currentEffectIndex);
        applyPreset_visualremote(currentEffectIndex);
      } 
   }

   void onButtonDownPress() {
      if (menuActive) {
        toggleMenuItem();
        return;
      }
      if (MagicFlowMode > 0) 
      {
        magic_flow(MagicFlowProgram);
      } else {
        do {
          currentEffectIndex--;

      
          if (currentEffectIndex < MenuChoiceStart) {
            currentEffectIndex = 60;
          }
          DEBUG_PRINTF("> Down effect %d %d \n", currentEffectIndex, MenuChoiceStart);
          DEBUG_PRINTF("preset_available[%u] = %s\n", currentEffectIndex, preset_available[currentEffectIndex] ? "true" : "false");

        } while (!preset_available[currentEffectIndex]);
        DEBUG_PRINTF("> Start Display effect %d \n", currentEffectIndex);
        applyPreset_visualremote(currentEffectIndex);
      } 
   }


    inline void handleRemote_visualremote(uint8_t *incomingData, size_t len) {
      message_structure_t *incoming = reinterpret_cast<message_structure_t *>(incomingData);

      if (len != sizeof(message_structure_t)) {
        Serial.printf("Unknown incoming ESP-NOW message received of length %u\n", len);
        return;
      }
      
      if (strcmp(last_signal_src, linked_remote) != 0) {
        DEBUG_PRINT(F("ESP Now Message Received from Unlinked Sender: "));
        DEBUG_PRINTLN(last_signal_src);     
        DEBUG_PRINTLN(incoming->button);     
        DEBUG_PRINTLN(incoming->program);     
        DEBUG_PRINTLN(incoming->seq[0]);     
        if (!SyncMode) {
          return;
        }
        if (
          (incoming->button != WIZMOTE_BUTTON_PROGRAM)
          ) {
            return;
          }
      }

      if (incoming->button == WIZMOTE_BUTTON_PROGRAM) {
          DEBUG_PRINT(F("Program: "));
        DEBUG_PRINTLN(incoming->program);
        sequenceNumber=0;

      }
      DEBUG_PRINTF("Button value: %u\n", incoming->button);
      uint32_t cur_seq = incoming->seq[0] | (incoming->seq[1] << 8) | (incoming->seq[2] << 16) | (incoming->seq[3] << 24);
      if (cur_seq == last_seq_visualremote) {
        return;
      }

      ButtonPressed = true;
      BroadcastProgram = false;    
      lastTime = millis();

      // if ((incoming->button != WIZMOTE_BUTTON_BRIGHT_DOWN_SHORT) && (incoming->button != WIZMOTE_BUTTON_BRIGHT_UP_SHORT)) {
      //   menuActive = false;
      // }
        Serial.printf("Incoming Button: %u\n", incoming->button);
      switch (incoming->button) {
        //        case WIZMOTE_BUTTON_OFF_SHORT             : togglePower_visualremote();                                            break;

        case WIZMOTE_BUTTON_OFF_SHORT             : togglePower_visualremote();                                            break;
        case WIZMOTE_BUTTON_OFF_LONG            : toggleMenu_visualremote();                                           break;
        case WIZMOTE_BUTTON_ON_SHORT            : setBrightness_visualremote();                                           break;
        case WIZMOTE_BUTTON_ON_LONG            : resetBrightness_visualremote();                                           break;
        
        case WIZMOTE_BUTTON_OFF_DOUBLE        : enableAP_visualremote(); break;
        case WIZMOTE_BUTTON_OFF_TRIPLE        : initWifi(); break;

        case WIZMOTE_BUTTON_NIGHT_SHORT          : broadcastProgram();                                break;
        case WIZMOTE_BUTTON_NIGHT_DOUBLE         : initWifi();                                break;
        case WIZMOTE_BUTTON_NIGHT_TRIPLE         : initWifi();                                break;
        case WIZMOTE_BUTTON_NIGHT_LONG           : toggleSyncMode_visualremote();                                break;
        case WIZMOTE_BUTTON_BRIGHT_UP_SHORT      : onButtonUpPress();                                               break;
        case WIZMOTE_BUTTON_BRIGHT_UP_LONG      : applyPreset_visualremote(6);    break;
        case WIZMOTE_BUTTON_BRIGHT_DOWN_SHORT    : onButtonDownPress();                                             break;
        case WIZMOTE_BUTTON_BRIGHT_DOWN_LONG    : applyPreset_visualremote(5);    break;

        case WIZMOTE_BUTTON_ONE_SHORT       : applyPreset_visualremote(1);    break;
        case WIZMOTE_BUTTON_ONE_DOUBLE      : //applyPreset_visualremote(7);    break;
        case WIZMOTE_BUTTON_ONE_TRIPLE      :
        case WIZMOTE_BUTTON_ONE_QUADRUPLE   : magic_flow(16);    break;;
        case WIZMOTE_BUTTON_ONE_LONG        : applyPreset_visualremote(20);    break;

        case WIZMOTE_BUTTON_TWO_SHORT       : applyPreset_visualremote(2);    break;
        case WIZMOTE_BUTTON_TWO_DOUBLE      : //applyPreset_visualremote(9);    break;
        case WIZMOTE_BUTTON_TWO_TRIPLE      : 
        case WIZMOTE_BUTTON_TWO_QUADRUPLE   : magic_flow(17);    break;
        case WIZMOTE_BUTTON_TWO_LONG        : applyPreset_visualremote(21);    break;

        case WIZMOTE_BUTTON_THREE_SHORT     : applyPreset3_visualremote(3);    break;
        case WIZMOTE_BUTTON_THREE_DOUBLE    : //increaseSpeed();    break;
        case WIZMOTE_BUTTON_THREE_TRIPLE:
        case WIZMOTE_BUTTON_THREE_QUADRUPLE    : magic_flow(18);    break;
        case WIZMOTE_BUTTON_THREE_LONG      : applyPreset_visualremote(22);    break;


        case WIZMOTE_BUTTON_FOUR_SHORT      : 
        case WIZMOTE_BUTTON_FOUR_DOUBLE     : applyPreset_visualremote(4);    break;
        case WIZMOTE_BUTTON_FOUR_TRIPLE     : 
        case WIZMOTE_BUTTON_FOUR_QUADRUPLE  : magic_flow(19);    break;
        case WIZMOTE_BUTTON_FOUR_LONG       : applyPreset_visualremote(23);    break;
      
        case WIZMOTE_BUTTON_PROGRAM         : applyPreset_visualremote(incoming->program);    break;

        default: break;
      }

      last_seq_visualremote = cur_seq;
    }

    void handleOverlayDraw() {
      Segment &seg = strip.getSegment(segmentId);

      uint32_t wifiColor = BLACK;  // default color

      switch (WiFi.status()) {
        case 4:
          wifiColor = RED;
          break;
        case 3:
          wifiColor = GREEN;
          break;
        case 2:
          wifiColor = ORANGE;
          break;
        case 1:
          wifiColor = PURPLE;
          break;
        case 0:
          wifiColor = BLUE;
          break;
        default:
          wifiColor = BLUE;  // Off
          break;
      }
  
      //strip.getSegment(segmentId).setPixelColor(segmentPixelOffset, wifiColor); 
      
      //strip.getSegment(segmentId).setPixelColor(segmentPixelOffset + 1, syncColor); 

      if (ButtonPressed) {     
        if (millis() - lastTime > timeOutMenu) {
          ButtonPressed = false;
        }   
        seg.setPixelColor(segmentPixelOffset, BLUE);       
      }

      if (BroadcastProgram)
      {        
        seg.setPixelColor(segmentPixelOffset, PURPLE);            
      }
      

      if (SyncModeChanged) {     
        if (millis() - lastTime > timeOutMenu) {
          SyncModeChanged = false;
        }   
        uint32_t syncColor = SyncMode ? GREEN : RED;
        strip.fill(syncColor);
        //strip.getSegment(segmentId).setPixelColor(segmentPixelOffset, WHITE);       
      }

      const Segment* segments = strip.getSegments();
      for (unsigned i = 0; i < strip.getSegmentsNum(); i++) {
        Segment& matrixSegment = strip.getSegment(i);
        if (!matrixSegment.is2D()) continue;

        if (menuActive) {
          strip.fill(CRGB::Black); // Clear the segment

          // Determine which icon to use based on menuIndex
          const byte (*iconData)[16] = (menuIndex == 0) ? wifi_icon : access_point_icon;
          uint32_t color = (menuIndex == 0) ? wifiColor : (apActive) ? CRGB::Green : CRGB::Red;

          // Plot the icon on the segment
          for (int y = 0; y < 16; y++) {
            for (int x = 0; x < 16; x++) {
              // Read the pixel value from PROGMEM
              byte pixelValue = pgm_read_byte(&iconData[y][x]);

              if (pixelValue == 1) {
                matrixSegment.setPixelColorXY(x, y, color);
              }
            }
          }
        }
      }

    }

    void loop() {
      if (UpdateBrightness) {
        applyBrightness_visualremote();
      }
      // Code to run in the main loop
      if (BroadcastProgram) {
        static time_t lastSend = 60000;
        if (millis () - lastSend >= 1000) {
          lastSend = millis ();
          DEBUG_PRINTLN("Broadcasting program");

          message_structure_t msg;
          msg.button = WIZMOTE_BUTTON_PROGRAM;
          msg.program = presetToApply; 
          // Use next sequence number
          uint32_t seq = nextSequenceNumber();
          msg.seq[0] = seq & 0xFF;
          msg.seq[1] = (seq >> 8) & 0xFF;
          msg.seq[2] = (seq >> 16) & 0xFF;
          msg.seq[3] = (seq >> 24) & 0xFF;
          if (!quickEspNow.send(ESPNOW_BROADCAST_ADDRESS, (uint8_t*)&msg, sizeof(msg)))
          {
                        
            repeat--;
            if (repeat <= 0) {
               BroadcastProgram = false;
            }
            
          } else {
            DEBUG_PRINTLN("Failed to send ESP-NOW message");
          }    
          
        }
      }
    
      
    }



    bool onEspNowMessage(uint8_t* sender, uint8_t* data, uint8_t len) {      
      handleRemote_visualremote(data, len);
      
      return true; // Override further processing
    }

     
};

// add more strings here to reduce flash memory usage
const char UsermodVisualRemote::_name[]    PROGMEM = "VisualRemote";
const char UsermodVisualRemote::_enabled[] PROGMEM = "enabled";
