
import network, urequests, utime, ntptime
from machine import Pin, SPI, Timer, reset, I2C


i2c=I2C(scl=Pin(5),sda=Pin(4),freq=100000)

# WiFi AP ssid and password
SSID = "ArViNd'S sd845"
PW   = "123456789"

URL = "https://coronavirus-19-api.herokuapp.com/countries/india"

# config parameters
TIMEZONE_HOUR_OFFSET = 5      # timezone hour offset
CLOCK_TIMER_DELAY    = 9000 # clock update delay (ms)
API_TIMER_DELAY      = 3000 # API query delay (ms)

# format string for displaying data
fmt = "{country} " \
      "case {cases}" \
      " today {todayCases} " \
      "death {deaths} " \
      "recov {recovered} " \
      "critical {critical} " \
      "update {time}"



data           = dict()
data_available = False
timer_api      = Timer(-1)
timer_clock    = Timer(-1)
timer_display  = Timer(-1)
led            = Pin(2, Pin.OUT, value=1)



# connect to WiFi
print("Connecting to WiFi...")
wifi = network.WLAN(network.STA_IF)
wifi.active(True)
wifi.connect(SSID, PW)
while not wifi.isconnected():
    pass
print("Connected.")

# decorator for checking WiFi status
def wifi_check_decorator(func):
    def wrapper(*args, **kwargs):
        if not wifi.isconnected():
            # stop timers
            timer_api.deinit()
            timer_clock.deinit()
            timer_display.deinit()
            # reboot
            reset()
        else:
            # run decorated functions
            led.value(0)
            func(*args, **kwargs)
            led.value(1)
    return wrapper

# query time from NTP server
@wifi_check_decorator
def query_time(timer):
    while True:
        try:
            ntptime.settime()
            break
        except:
            utime.sleep(1)

# query data from API
@wifi_check_decorator
def query_api(timer):
    global data, data_available
    try:
        data_available = False
        # query API
        response = urequests.get(URL)
        # query successful
        if response.status_code == 200:
            # parse data as dictionary
            data = response.json()
            response.close()
            # add query time
            local_time_sec = utime.time() + TIMEZONE_HOUR_OFFSET * 3600
            local_time = utime.localtime(local_time_sec)
            time = "{1:02d}/{2:02d} {3:02d}:{4:02d}".format(*local_time)
            data.update({'time': time})
            data_available = True
    except:
        pass

query_time(None)
query_api(None)

timer_clock.init(period=CLOCK_TIMER_DELAY,
                mode=Timer.PERIODIC,
                callback=query_time)

timer_api.init(period=API_TIMER_DELAY,
                mode=Timer.PERIODIC,
                callback=query_api)

output=fmt.format(**data)
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

