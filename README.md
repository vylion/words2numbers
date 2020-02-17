# Current state
- Reads a string of words referring to a numeral and prints the digit equivalent.

For example:  
`./bin/main "two hundred thousand, four hundred forty"` prints *200440*.

# To do

## Mixed text reading
- Expect to read a mixed text (numeral and plain text mixed together), maybe as a file or as a direct input
- Separate said mixed text into a list of chunks of pure plain text, and pure numeral string of words
- Split the list of chunks in 2 recursively
- For each leaf (chunk), evaluate the chunk (plain text evaluates to itself; numeral string evaluates to the equivalent integer value, converted back into a string)
- At every split, concatenate evaluations of both branches
- Parallelize on each split

## Proper testing
- Move the collection of assert calls & cout calls, away from the main file into proper test files
- End goal: use GTest

## Cleanup
- Add const keywords to non-modified arguments (like the "text" in the NumeralManager::analyze_numeral, or the "words" in the Trie operations)
- Properly alter types to better match their functions (like adding "unsigned" to many "pos" int arguments)
- Better implement the language-agnostic setup (make NumeralManager to read from a file, instead of having a separate .cpp file only with the "language_setup" function)
- Error handling
- Make the whole CLI interface (help/usage tooltip message, options to read a [list of] string[s] or a [list of] file[s], ...)
