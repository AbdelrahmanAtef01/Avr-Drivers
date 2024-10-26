#ifndef I2C_PRIVATE_H_
#define I2C_PRIVATE_H_

// I2C status codes
#define I2C_START_TRANSMITTED            0x08
#define I2C_REPEATED_START_TRANSMITTED    0x10
#define I2C_SLA_W_ACK                    0x18
#define I2C_SLA_R_ACK                    0x40
#define I2C_DATA_TRANSMITTED_ACK          0x28
#define I2C_DATA_RECEIVED_ACK             0x50
#define I2C_DATA_RECEIVED_NO_ACK          0x58

#endif /* I2C_PRIVATE_H_ */
