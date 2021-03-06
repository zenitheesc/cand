#pragma once
#include <cstring>
#include <iomanip>
#include <iostream>
#include <string>
#include <unistd.h>
#include <vector>

#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>

#include <linux/can.h>
#include <linux/can/raw.h>

class CAN {
private:
    int m_fileDescriptor;
    std::string m_interfaceName;

public:
    CAN(const std::string&);
    ~CAN();

    void socketWrite(const struct can_frame&);

    auto getFileDescriptor() const -> int;

    void setFilter(const struct can_filter&);
};

const CAN& operator<<(CAN&, struct can_frame&);
const struct can_frame& operator>>(CAN&, struct can_frame&);
std::ostream& operator<<(std::ostream&, struct can_frame&);