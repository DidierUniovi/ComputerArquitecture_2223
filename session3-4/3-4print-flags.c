#include <stdio.h>
#include <atc/linmem.h>

// Given a virtual address, the values of the flags of the page
// are printed on the screen. On top of these, the title passed
// as argument is also displayed.
void print_pte_flags(void *virtual_addr, char *title)
{
    unsigned int pte;
    unsigned int flags_vp;
    const unsigned int FLAG_MASK = 0xFFF;
    const unsigned int PRESENT_BIT_MASK = 0x001;
    const unsigned int READ_WRITE_BIT_MASK = 0x002;
    const unsigned int USER_KERNEL_BIT_MASK = 0x004;
    const unsigned int WRITE_THROUGH_BIT_MASK = 0x008;
    const unsigned int CACHE_DISABLED_BIT_MASK = 0x010;
    const unsigned int ACCESSED_BIT_MASK = 0x020;
    const unsigned int DIRTY_BIT_MASK = 0x040;
    const unsigned int PT_INDEX_BIT_MASK = 0x080;
    const unsigned int GLOBAL_PAGE_BIT_MASK = 0x100;

    // Print the title
    printf("%s\n", title);

    // Retrieve the entry in the page table for the virtual address
    if (get_pte(virtual_addr, &pte))
    {
        perror("Linmem module error");
        return;
    }

    // Is there PTE?
    if (pte)
    { // OK
        // Store the flags associated at the memory page
        flags_vp = pte & FLAG_MASK;

        ////////
        ///   Print the status of the flags associated to the page
        ////////
        if (flags_vp & PRESENT_BIT_MASK)
            printf("Present bit = 1\tPage present in memory\n");
        else
            printf("Present bit = 0\tPage is not present in memory\n");
        if(flags_vp & READ_WRITE_BIT_MASK)
            printf("Read/Write bit = 1\tPage can be read and write\n");
        else
            printf("Read/Write bit = 0\tPage can be read\n");
        if(flags_vp & USER_KERNEL_BIT_MASK)
            printf("User/Kernel bit = 1\tPage can be accessed by user\n");
        else
            printf("User/Kernel bit = 0\tPage can be accessed by OS\n");
        if (flags_vp & WRITE_THROUGH_BIT_MASK)
            printf("Write Through bit = 1\tPage uses Write Through policy\n");
        else
            printf("Write Through bit = 0\tPage doesn't use Write Through policy\n");
        if(flags_vp & CACHE_DISABLED_BIT_MASK)
            printf("Cache disabled bit = 1\tPage goes directly to MM\n");
        else
            printf("Cache disabled bit = 0\tPage goes directly to Cache\n");
        if(flags_vp & ACCESSED_BIT_MASK)
            printf("Accessed bit = 1\tPage has been accessed\n");
        else
            printf("Accessed bit = 0\tPage has not been accessed\n");
        if(flags_vp & DIRTY_BIT_MASK)
            printf("Dirty bit = 1\tPage has been written\n");
        else
            printf("Dirty bit = 0\tPage has not been written\n");
        if(flags_vp & PT_INDEX_BIT_MASK)
	    printf("Page Table Attribute Index = 1\n");
	else
	    printf("Page Table Attribute Index = 0\n");
        if(flags_vp & GLOBAL_PAGE_BIT_MASK)
            printf("Global bit = 1\tPTE is valid for all tasks\n");
        else
            printf("Global bit = 0\tPTE is not valid for all tasks\n");
    }
    else
    {
        fprintf(stderr, "Page %.5Xh does not have a page table entry\n",
            (unsigned int)virtual_addr >> 12);
    }
}

int main(void)
{
    int local = 0xABCDEF01;

    print_pte_flags(&local, "Local variable\n-----------------");

    printf("\n---- Press [ENTER] to continue");
    getchar();

    return 0;
}
