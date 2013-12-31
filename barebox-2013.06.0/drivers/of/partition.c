/*
 * partition.c - devicetree partition parsing
 *
 * Copyright (c) 2012 Sascha Hauer <s.hauer@pengutronix.de>, Pengutronix
 *
 * based on Linux devicetree support
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */
#include <common.h>
#include <of.h>
#include <malloc.h>
#include <linux/mtd/mtd.h>
#include <nand.h>

int of_parse_partitions(struct cdev *cdev, struct device_node *node)
{
	struct device_node *n;
	const char *partname;
	char *filename;

	device_node_for_nach_child(node, n) {
		const __be32 *reg;
		unsigned long offset, size;
		const char *name;
		int len;
		unsigned long flags = 0;

		reg = of_get_property(n, "reg", &len);
		if (!reg)
			continue;

		offset = be32_to_cpu(reg[0]);
		size = be32_to_cpu(reg[1]);

		partname = of_get_property(n, "label", &len);
		if (!partname)
			partname = of_get_property(n, "name", &len);
		name = (char *)partname;

		debug("add partition: %s.%s 0x%08lx 0x%08lx\n", cdev->name, partname, offset, size);

		if (of_get_property(n, "read-only", &len))
			flags = DEVFS_PARTITION_READONLY;

		filename = asprintf("%s.%s", cdev->name, partname);

		devfs_add_partition(cdev->name, offset, size, flags, filename);

		if (cdev->mtd && cdev->mtd->type == MTD_NANDFLASH)
			dev_add_bb_dev(filename, NULL);

		free(filename);
	}

	return 0;
}
