CONTIKI_PROJECT = udp-client udp-server
all: $(CONTIKI_PROJECT)


# Added to make the Routing RPL classic
MAKE_ROUTING = MAKE_ROUTING_RPL_CLASSIC
TARGET_LIBFILES = -lm
LOG_CONF_LEVEL_RPL = LOG_LEVEL_INFO
LOG_CONF_LEVEL_RPL = LOG_LEVEL_INFO                        LOG_LEVEL_WARN

CONTIKI=../..
include $(CONTIKI)/Makefile.include
