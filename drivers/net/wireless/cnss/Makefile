# Makefile for CNSS platform driver

# [WLAN][SHARP] Customize Start
#                 2015.08.21 register resume function to workqueue to compress
#                 system resuming time. 
ccflags-y += -D SH_WIFI_CUSTOMIZE
# [WLAN][SHARP] Customize End

cnsscore-objs += cnss.o ../wcnss/qcomwlan_secif.o
obj-$(CONFIG_CNSS) += cnsscore.o
obj-$(CONFIG_WCNSS_MEM_PRE_ALLOC) += ../wcnss/wcnss_prealloc.o
