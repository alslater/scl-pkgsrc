# $NetBSD: buildlink3.mk,v 1.16 2015/05/23 06:40:15 kefren Exp $

BUILDLINK_TREE+=	ndesk-dbus-glib

.if !defined(NDESK_DBUS_GLIB_BUILDLINK3_MK)
NDESK_DBUS_GLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ndesk-dbus-glib+=	ndesk-dbus-glib>=0.4.1
BUILDLINK_ABI_DEPENDS.ndesk-dbus-glib+=	ndesk-dbus-glib>=0.4.1nb15
BUILDLINK_PKGSRCDIR.ndesk-dbus-glib?=	../../sysutils/ndesk-dbus-glib

.include "../../lang/mono/buildlink3.mk"
.include "../../sysutils/ndesk-dbus/buildlink3.mk"
.endif # NDESK_DBUS_GLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-ndesk-dbus-glib
