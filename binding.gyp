{
  "targets": [
    {
      "target_name": "protocol_capture",
      "sources": [ "ip_capture.cpp" ],
      "include_dirs": [
        "<!(node -p \"require('node-addon-api').include\")",
        "C:/Program Files/Npcap/Include"
      ],
      "libraries": [
        "C:/Program Files/Npcap/Lib/x64/wpcap.lib"
      ]
    }
  ]
}
