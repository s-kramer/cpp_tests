#include <inttypes.h>
#include <stdlib.h>
#include <stdio.h>
#include <elf.h>
#pragma pack(push)
#pragma pack(push,1)

typedef struct
{
    uint8_t  e_ident[16];
    uint16_t e_type;
    uint16_t e_machine;
    uint32_t e_version;
    uint32_t e_entry;
    uint32_t e_phoff;
    uint32_t e_shoff;
    uint32_t e_flags;
    uint16_t e_ehsize;
    uint16_t e_phentsize;
    uint16_t e_phnum;
    uint16_t e_shentsize;
    uint16_t e_shnum;
    uint16_t e_shstrndx;
} Elf32Hdr;

typedef struct
{
    uint32_t sh_name;
    uint32_t sh_type;
    uint32_t sh_flags;
    uint32_t sh_addr;
    uint32_t sh_offset;
    uint32_t sh_size;
    uint32_t sh_link;
    uint32_t sh_info;
    uint32_t sh_addralign;
    uint32_t sh_entsize;
} Elf32SectHdr;

#pragma pack(pop)

int main(int argc, char const *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <elf_file>\n", argv[0]);
        return -1;
    }

    FILE* ElfFile = fopen(argv[1], "r");
    char* SectNames = NULL;
    /* Elf32Hdr elfHdr; */
    Elf32_Ehdr elfHdr;
    Elf32SectHdr sectHdr;
    uint32_t idx;

    // read ELF header
    fread(&elfHdr, 1, sizeof elfHdr, ElfFile);

    // read section name string table
    // first, read its header
    fseek(ElfFile, elfHdr.e_shoff + elfHdr.e_shstrndx * sizeof sectHdr, SEEK_SET);
    fread(&sectHdr, 1, sizeof sectHdr, ElfFile);

    // next, read the section, string data
    SectNames = malloc(sectHdr.sh_size);
    fseek(ElfFile, sectHdr.sh_offset, SEEK_SET);
    fread(SectNames, 1, sectHdr.sh_size, ElfFile);

    // read all section headers
    for (idx = 0; idx < elfHdr.e_shnum; idx++)
    {
        const char* name = "";

        fseek(ElfFile, elfHdr.e_shoff + idx * sizeof sectHdr, SEEK_SET);
        fread(&sectHdr, 1, sizeof sectHdr, ElfFile);

        // print section name
        if (sectHdr.sh_name)
            name = SectNames + sectHdr.sh_name;
        printf("%2u %s\n", idx, name);
    }

    return 0;
}
