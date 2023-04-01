# TARGET := iphone:clang:latest:7.0
ARCHS = arm64

TARGET=iphone:clang:12.4
INSTALL_TARGET_PROCESSES = identityservicesd Preferences imagent IMCore IMDaemonCore MobileSMS SpringBoard
SYSROOT = $(THEOS)/sdks/iPhoneOS12.4.sdk


include $(THEOS)/makefiles/common.mk

TWEAK_NAME = PNRGateway

PNRGateway_FILES = Tweak.x
PNRGateway_CFLAGS = -fobjc-arc -Wno-nullability-completeness

PNRGateway_LIBRARIES = mryipc
PNRGateway_PRIVATE_FRAMEWORKS = IMCore
# PNRGateway_CFLAGS = -fobjc-arc -I./MyFramework.framework/Headers
# PNRGateway_LDFLAGS = -L./MyFramework.framework
# PNRGateway_EXTRA_FRAMEWORKS = IDS

include $(THEOS_MAKE_PATH)/tweak.mk
