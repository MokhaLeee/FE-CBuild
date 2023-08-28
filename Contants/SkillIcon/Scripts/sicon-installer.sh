#!/bin/bash

SOURCE_DIR=Sources
INSTALLER=SkillIconInstaller.event
HEADER=SkillIconDefs.h

rm -f $INSTALLER $HEADER

echo -e "// Auto generated at $(date)\n" > $INSTALLER

echo -e "// Auto generated at $(date)\n" > $HEADER
echo -e "#ifndef EA_STDLIB_EVENT /* This file should not be included by EA */\n" >> $HEADER
echo -e "#ifndef SICON_CONFIG_INSTALLED" >> $HEADER
echo -e "#define SICON_CONFIG_INSTALLED\n" >> $HEADER

all_sources=$(ls $SOURCE_DIR/)

for base_name in $(echo $all_sources | sed 's/.png//g'); do
    echo -e "SICON_$base_name:\n\t#incbin \"$SOURCE_DIR/$base_name.4bpp\"\n" >> $INSTALLER
    echo -e "extern const unsigned char SICON_$base_name[];" >> $HEADER
done

echo -e "\n#endif /* SICON_CONFIG_INSTALLED */" >> $HEADER
echo -e "\n#endif /* EA_STDLIB_EVENT */" >> $HEADER
