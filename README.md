# homebridge-rfoutlets
A plug-in for controlling Remote Frequency (rf) outlets.

This plug-in is developed especially for controlling 433MHz RF sockets, which can be purchased at a reasonable price. (i. e.[these](https://www.amazon.de/Brennenstuhl-Funkschalt-Set-Funksteckdosen-Innenbereich-Kindersicherung/dp/B001AX8QUM "Brennenstuhl Wireless Outlets"). Since Homebridge handles status information, you will always know if you have left the device turned on.

It was tested on a Raspberry Pi 3 with Ubuntu and Node. js v6.9.0. This should work on most Raspberry Pi models.

Supports ```lights```, ```switches```, and ```fans```

## Installation

- Install homebridge  
`sudo npm install -g homebridge`

- Install homebridge-rfoutlets  
`sudo npm install -g homebridge-rfoutlets`

- Update your homebridge configuration
```
"accessories": [{
        "accessory": "RFOutlet",
        "name": "Outlet:A",
        "type": "Switch",
        "manufacturer": "",
        "model": "",
        "serial": " ",
        "rf_on": 4480259,
        "rf_off": 4480268
    }]
```

## Notes

It is necessary that the user from whom homebridge is started is on the *sudoers* list, because the executable file (codesend) requires root privileges.
For detailed instructions on how to record RF signals and set up the Pi for transmission, see[here] (https://www.samkear.com/hardware/control-power-outlets-wirelessly-raspberry-pi "Pi 433Mhz Transmitter Guide"). Note: The web part of the guide is not required.

When this doesn't work, follow these steps:

1. Open the sudoers file:
```sudo visudo -f /etc/sudoers```

2. Add the following line at the end:
```<user> ALL=(root) NOPASSWD: <path_to_codesend>```


## Configuration

- ```name```: Name of your device (**required**)
- ```type```: `Light`, `Switch`, or `Fan` (**required**)
- ```rf_on```: RF signal to turn the outlet on (**required**)
- ```rf_off```: RF signal to turn the outlet off (**required**)
- ```manufacturer```: manufacturer of the device plugged into the outlet (*optional*, defaults to *blank*)
- ```model```: model of the device plugged into the outlet (*optional*, defaults to *blank*)
- ```serial```: serial number of the device plugged into the outlet (*optional*, defaults to *blank*)


See `sample-config.json`
