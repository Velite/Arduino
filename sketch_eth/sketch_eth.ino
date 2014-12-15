#include <EtherCard.h>
#include <LiquidCrystal.h>

#define STATIC 0  // set to 1 to disable DHCP (adjust myip/gwip values below)

#if STATIC
// ethernet interface ip address
static byte myip[] = { 
  192,168,1,40 };
// gateway ip address
static byte gwip[] = { 
  192,168,1,1 };
#endif

// ethernet mac address - must be unique on your network
static byte mymac[] = { 
  0x74,0x69,0x69,0x2D,0x30,0x31 };

byte Ethernet::buffer[500]; // tcp/ip send and receive buffer

char page[] PROGMEM =
"HTTP/1.0 503 Service Unavailable\r\n"
"Content-Type: text/html\r\n"
"Retry-After: 600\r\n"
"\r\n"
"<!DOCTYPE html><html lang=\"en\">"
"<head><title>"
"Service Temporarily Unavailable"
"</title></head>"
"<body>"
"<h3>This service is currently unavailable</h3>"
"<p><em>"
"The main server is currently off-line.<br />"
"Please try again later."
"</em></p>"
"</body>"
"</html>"
;

LiquidCrystal lcd(8, 13, 9, 4, 5, 6, 7);

void setup(){
//  Serial.begin(57600);
//  Serial.println("\n[backSoon]");
  
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("Starting");

/*
  if (ether.begin(sizeof Ethernet::buffer, mymac) == 0) 
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Failed");
  }
#if STATIC
  ether.staticSetup(myip, gwip);
#else
  if (!ether.dhcpSetup())
  {
        lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("DHCP failed");
  }
#endif
*/
//    lcd.setCursor(0,0);
//    lcd.print("IP: " + ether.myip[0]);
//  ether.printIp("IP:  ", ether.myip);
//  ether.printIp("GW:  ", ether.gwip);  
//  ether.printIp("DNS: ", ether.dnsip);  
  
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Done");
}

void loop(){
  // wait for an incoming TCP packet, but ignore its contents
 /* if (ether.packetLoop(ether.packetReceive())) {
    memcpy_P(ether.tcpOffset(), page, sizeof page);
    ether.httpServerReply(sizeof page - 1);
    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Get request");
  }*/
}
