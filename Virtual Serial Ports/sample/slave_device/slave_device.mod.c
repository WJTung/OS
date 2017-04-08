#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x2b22e0c3, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x70b3da6e, __VMLINUX_SYMBOL_STR(debugfs_remove) },
	{ 0x24598c4e, __VMLINUX_SYMBOL_STR(misc_deregister) },
	{ 0x774f6678, __VMLINUX_SYMBOL_STR(misc_register) },
	{ 0xc6940883, __VMLINUX_SYMBOL_STR(debugfs_create_file) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x10cde6fd, __VMLINUX_SYMBOL_STR(inet_ntoa) },
	{ 0x60b7c2c6, __VMLINUX_SYMBOL_STR(kconnect) },
	{ 0x218940fa, __VMLINUX_SYMBOL_STR(ksocket) },
	{ 0x84856d65, __VMLINUX_SYMBOL_STR(inet_addr) },
	{ 0xb1ff2689, __VMLINUX_SYMBOL_STR(kclose) },
	{ 0x4f6b400b, __VMLINUX_SYMBOL_STR(_copy_from_user) },
	{ 0x69acdf38, __VMLINUX_SYMBOL_STR(memcpy) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x8d3ad329, __VMLINUX_SYMBOL_STR(pv_mmu_ops) },
	{ 0x65a5675c, __VMLINUX_SYMBOL_STR(current_task) },
	{ 0x4c4fef19, __VMLINUX_SYMBOL_STR(kernel_stack) },
	{ 0xf0fdf6cb, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0x4f8b5ddb, __VMLINUX_SYMBOL_STR(_copy_to_user) },
	{ 0x3fdb3de0, __VMLINUX_SYMBOL_STR(krecv) },
	{ 0x9b388444, __VMLINUX_SYMBOL_STR(get_zeroed_page) },
	{ 0x4302d0eb, __VMLINUX_SYMBOL_STR(free_pages) },
	{ 0xdb072d35, __VMLINUX_SYMBOL_STR(__get_page_tail) },
	{ 0x4c9d28b0, __VMLINUX_SYMBOL_STR(phys_base) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=ksocket";


MODULE_INFO(srcversion, "5086B75EB67485A48C1E07D");
