from machine import Pin ,I2C
import time
i2c=I2C(scl=Pin(5),sda=Pin(4),freq=100000)

  
output="India case 66 today 12 death 13 recov 43 critical 0 update 03/26 13:50"
print(output)
x = output.rsplit(" ")
cases=x[2]

todaycases=x[4]

deaths=x[6]

recovered=x[8]

dat=x[12]
dat=dat.rsplit("/")
date=dat[1]

tim=x[13]
tim=tim.rsplit(":")
timie=tim[0]

payload='c'+cases+'t'+todaycases+'d'+deaths+'r'+recovered+'e'+date+'m'+timie
print(payload)
i2c.writeto(0x3a,payload)


#i2c.writeto(0x3a,'b')
