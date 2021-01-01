#include <iostream>

class USBDevice {
private:
    long m_id;
public:
    USBDevice(const long &id_in): m_id(id_in){}
    long getID() const { return m_id; }
    void setID(const long &id_in) { m_id = id_in; }
    void plugAndPlay() {}
};

class NetworkDevice {
private:
    long m_id;
public:
    NetworkDevice(const long &id_in): m_id(id_in) {}
    long getID() const { return m_id; }
    void setID(const long &id_in) { m_id = id_in; }
    void networking() {}
};

class USBNetworkDevice : public USBDevice, public NetworkDevice {
public:
    USBNetworkDevice(const long &usb_id, const long &net_id): 
        USBDevice(usb_id), NetworkDevice(net_id) {}
};

int main() {

    USBNetworkDevice my_device(12, 32);

    // my_device can use all methods from USB and Network
    my_device.networking();
    my_device.plugAndPlay();

    // Ambiguous Case
    // Specify Base Class name
    std::cout << my_device.NetworkDevice::getID() << std::endl;
    std::cout << my_device.USBDevice::getID() << std::endl;

    return 0;
}