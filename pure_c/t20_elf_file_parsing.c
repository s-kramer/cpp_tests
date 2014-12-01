#include <inttypes.h>
#include <stdlib.h>
#include <stdio.h>
#include <elf.h>
#pragma pack(push)
#pragma pack(push,1)

#pragma pack(pop)

int main(int argc, char const *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <elf_file>\n", argv[0]);
        return -1;
    }

    FILE* elf_file = fopen(argv[1], "r");
    char* SectNames = NULL;
    /* Elf32Hdr elf_hdr; */
    Elf32_Ehdr elf_hdr;
    Elf32_Phdr elf_phdr;
    Elf32_Shdr sect_hdr;
    uint32_t idx;

    // read ELF header
    fread(&elf_hdr, 1, sizeof elf_hdr, elf_file);

    /* Get elf file segment header */
    fseek(elf_file, elf_hdr.e_phoff, SEEK_SET);
    fread(&elf_phdr, 1, sizeof(elf_phdr), elf_file);

    // read section name string table
    // first, read its header
    fseek(elf_file, elf_hdr.e_shoff + elf_hdr.e_shstrndx * sizeof sect_hdr, SEEK_SET);
    fread(&sect_hdr, 1, sizeof sect_hdr, elf_file);

    // next, read the section, string data
    SectNames = malloc(sect_hdr.sh_size);
    fseek(elf_file, sect_hdr.sh_offset, SEEK_SET);
    fread(SectNames, 1, sect_hdr.sh_size, elf_file);

    // read all section headers
    for (idx = 0; idx < elf_hdr.e_shnum; idx++)
    {
        const char* name = "";

        fseek(elf_file, elf_hdr.e_shoff + idx * sizeof sect_hdr, SEEK_SET);
        fread(&sect_hdr, 1, sizeof sect_hdr, elf_file);

        // print section name
        if (sect_hdr.sh_name)
            name = SectNames + sect_hdr.sh_name;
        printf("%2u %s\n", idx, name);
    }

    return 0;
}
