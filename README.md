
The domain chosen was transport domain. The sentences were chosen accordingly. For English, the Stanford Parser was used to obtain the Phrase structure trees. A script was written which allowed the extraction of grammar from these Phrase structure trees. After extracting the grammar, the next task was to convert the grammar into CNF. Instead of the manual method, another script was written which did the same. Now that the CNF grammar is available,it can be used for the CYK algorithm. The main tasks in the script were to eliminate left recursion and perform left factoring. Transitivity in the rules was also removed and bought into CNF form. The probabilities for the grammar rules were also calculated and assigned.
Observations:

• The main observation was that when converted to CNF form, the number of grammar
rules become significantly higher when as compared to PCFG form.

• The punctuations were accounted as grammar symbols as well.

• The nouns are a significant number and vary as many proper nouns have their place
in the domain.

• Among the verbs, words like transported, know,reserved etc., have high probabilities
as most of the sentences were taken from FAQ's.

The CYK algorithm:

The main motivation behind this algorithm is that Top-down and bottom-up parsing both lead to repeated substructures. The main idea behind this algorithm is to use previously computed grammar rules with probabilities to compute the next probable grammar rule. Using dynamic programming we are able to eliminate most recursion by memoizing the results in a two dimensional grid. Each cell in the grid holds a value for the head of the grammar rule, a vector for the body of the grammar rule, a value for probablity of the grammar rule. It also holds values corresponding to the previous productions for ease of backtracking. The CNF grammar generated in the previous part was used as an input to this part for training. For testing, sentences relating to the domain were used.

Assumptions:

• The words are case sensitive

• The input grammar to the CYK parser should be strings of terminals&Non-terminals
separated by spaces.

Pro's:

• This algorithm is easy to understand as it just extends the naive approach.

• The time for this approach is in the order of O(n^3) as the loops for traversing the
grid and a loop for traversing the cells in the array. But if matching the rules in cells
is taken into account this may become higher unless efficient hashing is used.

• A parse tree can also be constructed by backtracking from the most probable
production.

Cons:

• • •
The grammar must only be in CNF form.

If the grammar is huge then the algorithm is inefficient.

The words in the test sentence must be restricted to the domain.
