Array of Pointers:

Let's say we have a malloc'ed null terminated array of string pointers of this:

char *str = "abc,def,ghi";
char **ptr = split(str);

When we allocate the pointer array, we choose (n + 1) so that the last element of this array is a NULL pointer

It's important to note that while we have (n + 1) malloc'ed pointers, only n strings are heap allocated because
NULL PTR does not need to be heap allocated (it's also safe to free NULL)

Suppose in memory everything starting with 0xA is stack allocated, and 0xB-F is heap allocated, we'd have:

				Address				Value At Location
char *str		0x7bfff4700020		0x7bfff4700020 "0,12,345,6789"
char **ptr:		0x7fffffffe0d0		0x7c3ff5be0010

The value ptr has points to the start of the array of pointers
				Address					Value
ptr[0]			0x7c3ff5be0010			0x7c1ff5be0010 "0"
ptr[1]			0x7c3ff5be0018			0x7c1ff5be0030 "12"
ptr[2]			0x7c3ff5be0020			0x7c1ff5be0050 "345"
ptr[3]			0x7c3ff5be0028			0x7c1ff5be0070 "6789"
ptr[4]			0x7c3ff5be0030			0x0
