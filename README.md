# UDP Packet Parser 📦

`udp-packet-parser` is a command-line tool designed to read, parse, and display UDP packets from PCAP (Packet Capture) files in the terminal. This project aims to provide a hands-on experience to gain familiarity with working with PCAP file structure and understanding the UDP packet format. 🌐

## Table of Contents

- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Output](#output)
- [Contributing](#contributing)
- [License](#license)

## Features ✨

- Read PCAP files and parse UDP packets
- Display UDP packet information on the command line terminal
- Easy to use and understand command-line tool
- Great for learning and understanding PCAP file structure and UDP packet format
- Comes with two example PCAP files to get you started

## Installation ⚙️

1. Clone this repository:

`git clone https://github.com/zulfkhar00/udp-packet-parser.git`

2. Compile the project:

```
cd udp-packet-parser
make udp_reader
```

3. To check that everything is working properly, try running the program with one of the included example PCAP files:

```
./udp_reader example1.pcap
```

## Usage 🚀

To use the UDP Packet Parser, execute the compiled binary with the desired input PCAP file:

```
./udp_reader <input_pcap_file>
```

For example:

```
./udp_reader example1.pcap
```

This command will read, parse, and display the UDP packets present in the specified PCAP file.

## Output 💡

The output format on the terminal looks like this:

```
plaintext
Source Port: 443
Destination Port: 58705
Length: 44
Checksum: 49769
XbLw$.A.\_5..+{....H.FS.x].~=.A...>}'.
```

## Contributing 🤝

1. Fork the Repository

2. Clone your fork

3. Create your feature branch (`git checkout -b feature/AmazingFeature`)

4. Commit your changes (`git commit -m 'Add some AmazingFeature'`)

5. Push to the branch (`git push origin feature/AmazingFeature`)

6. Open a Pull Request

## License 📄

This project is licensed under the MIT License. Please see the [LICENSE](LICENSE) file for more details.
