ifneq (, $(filter F%, $(SH_BUILD_ID)))
EXTRA_CFLAGS += -DSHGRIP_FACTORY_MODE_ENABLE
endif

ifeq ($(CONFIG_SENSOR_SHGRIP_MODEL1),y)
obj-$(CONFIG_SENSOR_SHGRIP) += 001/
else ifeq ($(CONFIG_SENSOR_SHGRIP_MODEL2_1),y)
obj-$(CONFIG_SENSOR_SHGRIP) += 002/201/
else ifeq ($(CONFIG_SENSOR_SHGRIP_MODEL2_2),y)
obj-$(CONFIG_SENSOR_SHGRIP) += 002/202/
else
obj-$(CONFIG_SENSOR_SHGRIP) += 003/
endif
