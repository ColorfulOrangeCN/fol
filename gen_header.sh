#~ /bin/bash
echo "// Functional OI Library begin"
FROOT=$(dirname "$0")
cat $FROOT/src/defination.hpp | $FROOT/translate.py
cat $FROOT/src/utility.hpp | $FROOT/translate.py
cat $FROOT/src/range.hpp | $FROOT/translate.py
echo "// Functional OI Library end"
