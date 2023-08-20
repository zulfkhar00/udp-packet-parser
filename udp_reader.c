#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define GLOBAL_HEADER_SIZE 24
#define REI 50 // record, ethernet, ip header size
#define RECORD_HEADER_SIZE 16
#define ETHERNET_HEADER_SIZE 14
#define IP_HEADER_SIZE 20

struct udp_header
{
    unsigned short source_port;
    unsigned short dest_port;
    unsigned short length;
    unsigned short checksum;
};

void print_udp_headers(struct udp_header *header)
{
    printf("Source Port: %d\n", header->source_port);
    printf("Destination Port: %d\n", header->dest_port);
    printf("Length: %d\n", header->length);
    printf("Checksum: %d\n", header->checksum);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("You have to provide file name! (./solution <pcap file>)\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "rb");
    if (!fp)
    {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    // skip global header
    fseek(fp, GLOBAL_HEADER_SIZE, SEEK_SET);
    while (!feof(fp))
    {
        // record, ethernet, ip headers
        char rie[REI];
        if (fread(rie, 1, REI, fp) < REI)
        {
            break;
        }
        // read UDP header
        struct udp_header udp;
        if (fread(&udp, 1, sizeof(udp), fp) < sizeof(udp))
        {
            break;
        }
        // converting integer from network byte order to host byte order
        udp.source_port = ntohs(udp.source_port);
        udp.dest_port = ntohs(udp.dest_port);
        udp.length = ntohs(udp.length);
        udp.checksum = ntohs(udp.checksum);
        // displaying the udp packet information
        print_udp_headers(&udp);
        // reading, displaying data section
        char data[65535];
        fread(data, udp.length - 8, 1, fp);
        for (int i = 0; i < udp.length - 8; i++)
        {
            if (isprint(data[i]))
                printf("%c", data[i]);
            else
                printf(".");
        }
        printf("\n");
    }

    fclose(fp);

    return 0;
}
