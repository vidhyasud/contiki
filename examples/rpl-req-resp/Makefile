CONTIKI_PROJECT = node
all: $(CONTIKI_PROJECT)

PLATFORMS_EXCLUDE = sky z1 native
BOARDS_EXCLUDE = launchpad/cc1350-4 launchpad/cc2640r2
MAKE_ROUTING = MAKE_ROUTING_RPL_CLASSIC

MODULES_REL += ../benchmarks/testbeds


CONTIKI=../..

include $(CONTIKI)/Makefile.dir-variables
MODULES += $(CONTIKI_NG_SERVICES_DIR)/deployment
MODULES += $(CONTIKI_NG_SERVICES_DIR)/simple-energest

CONFIG?=CONFIG_TSCH_OPTIMS

ifeq ($(CONFIG),CONFIG_CSMA)
MAKE_MAC = MAKE_MAC_CSMA
else ifeq ($(CONFIG),CONFIG_TSCH)
MAKE_MAC = MAKE_MAC_TSCH
MODULES += $(CONTIKI_NG_SERVICES_DIR)/orchestra
else ifeq ($(CONFIG),CONFIG_TSCH_OPTIMS)
MAKE_MAC = MAKE_MAC_TSCH
MODULES += $(CONTIKI_NG_SERVICES_DIR)/orchestra
CFLAGS += -DCONFIG_OPTIMS=1
else ifeq ($(CONFIG),CONFIG_TSCH_OPTIMS2)
MAKE_MAC = MAKE_MAC_TSCH
MODULES += $(CONTIKI_NG_SERVICES_DIR)/orchestra
CFLAGS += -DCONFIG_OPTIMS=2
endif

include $(CONTIKI)/Makefile.include
