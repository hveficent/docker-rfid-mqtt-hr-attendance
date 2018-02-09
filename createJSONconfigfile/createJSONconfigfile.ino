// ArduinoJson - arduinojson.org
// Copyright Benoit Blanchon 2014-2018
// MIT License

#include <ArduinoJson.h>

void setup() {
  // Initialize Serial port
  Serial.begin(115200);
  while (!Serial) continue;

  // Memory pool for JSON object tree.
  //
  // Inside the brackets, 200 is the size of the pool in bytes.
  // Don't forget to change this value to match your JSON document.
  // Use arduinojson.org/assistant to compute the capacity.
  DynamicJsonBuffer jsonBuffer;
  //StaticJsonBuffer<200> jsonBuffer;

  // StaticJsonBuffer allocates memory on the stack, it can be
  // replaced by DynamicJsonBuffer which allocates in the heap.
  //
  // DynamicJsonBuffer  jsonBuffer(200);

  // Create the root of the object tree.
  //
  // It's a reference to the JsonObject, the actual bytes are inside the
  // JsonBuffer with all the other nodes of the object tree.
  // Memory is freed when jsonBuffer goes out of scope.
  JsonObject& jsonFile   = jsonBuffer.createObject();

  // Add values in the object
  //
  // Most of the time, you can rely on the implicit casts.
  // In other case, you can do root.set<long>("time", 1351824120);
  jsonFile["odoo_host"] = "192.168.1.37";                                   ///////////////********** QUE VALOR PONER? *************//////////////
  jsonFile["odoo_port"] = "8069";
  jsonFile["odoo_user"] = "admin";
  jsonFile["odoo_password"] = "admin";
  jsonFile["odoo_database"] = "esp8266";                              ///////////////********** QUE VALOR PONER? *************//////////////

  // Add a nested array.
  //
  // It's also possible to create the array separately and add it to the
  // JsonObject but it's less efficient.
  //JsonArray& data = root.createNestedArray("data");
  //data.add(48.756080);
  //data.add(2.302038);

  jsonFile.printTo(Serial);
  // This prints:
  // {"sensor":"gps","time":1351824120,"data":[48.756080,2.302038]}

  Serial.println();

  jsonFile.prettyPrintTo(Serial);
  // This prints:
  // {
  //   "sensor": "gps",
  //   "time": 1351824120,
  //   "data": [
  //     48.756080,
  //     2.302038
  //   ]
  // }
}

void loop() {
  // not used in this example
}

