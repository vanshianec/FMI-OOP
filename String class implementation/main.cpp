#define DOCTEST_CONFIG_IMPLEMENT
#define TEST_CASE DOCTEST_TEST_CASE
#include "doctest.h"
#include "string.h"

TEST_CASE("Initialization tests")
{
	String s1;
	CHECK(s1.getData() == nullptr);
	CHECK(s1.getLength() == 0);

	String s2("");
	CHECK(s1 == s2);

	String s3("a");
	CHECK(!(s1 == s3));
	CHECK(s1 != s3);

	String s4('a');
	CHECK(s3 == s4);

	String s5("Gosho");
	String s6("Gosho");
	CHECK(s5 == s6);
	CHECK(!(s5 != s6));

	String s7(s6);
	CHECK(s7 == s6);
}

TEST_CASE("Assignment tests")
{
	String s1("Pesho"), s2;
	String s3 = s1;

	CHECK(s1 == s3);
	CHECK(s1 != s2);
	CHECK(s3 != s2);

	s2 = s3;

	CHECK(s2 == s1);
	CHECK(s2 == s3);

	String s5, s6, s7;
	s5 = s6 = s7 = s1;
	CHECK(s1 == s5);
	CHECK(s1 == s6);
	CHECK(s1 == s7);
	CHECK(s7 == "Pesho");

	String s8, s9;
	s8 = s9;
	CHECK(s8 == s9);
	s8 = s8;
	CHECK(s8 == s8);
}

TEST_CASE("Data retrieving tests")
{
	String s1;
	CHECK(s1.getLength() == 0);
	CHECK(s1.getData() == nullptr);
	CHECK(s1.isEmpty());

	String s2('f');
	CHECK(s2.getLength() == 1);
	CHECK(!s2.isEmpty());
	CHECK(s2.getData() != nullptr);
	CHECK(s2[0] == 'f');

	String s3("Pesho");
	CHECK(s3.getLength() == 5);
	CHECK(!s3.isEmpty());
	CHECK(s3[0] == 'P');
	CHECK(s3[2] == 's');
	CHECK(s3[4] == 'o'); 
	s3[4] = 'S';
	CHECK(s3[4] == 'S');
	s3[0] = '1';
	CHECK(s3[0] == '1');
}

TEST_CASE("Addition assignment operator tests")
{
	String s1, s2, s3;
	s1 += s2;
	CHECK(s1 == s3);
	s1 += 'f';
	s3 += 'f';
	CHECK(s1 == s3);
	CHECK(s1 != s2);

	String s4("Test");
	s1 += "Test";
	s3 += s4;
	CHECK(s1 == s3);

	String s5("fTest");
	s2 += s5;
	CHECK(s1 == s2);
}

TEST_CASE("Concat tests")
{
	String s1, s2, s3;
	s3 = s1.concat(s2);
	CHECK(s3 == s1);
	CHECK(s3 == s2);
	s1 += "Pesho";
	s2 += "Misho";
	s3 = s1.concat(s2);
	CHECK(s3 == "PeshoMisho");
	CHECK(s1 == "Pesho");
	CHECK(s2 == "Misho");
	CHECK(s1.concat(s2) == "PeshoMisho");
	s1 = s1.concat(s2);
	CHECK(s1 == s3);
	s2 = s1.concat(s2);
	CHECK(s2 == "PeshoMishoMisho");
	CHECK(s3 == "PeshoMisho");
}

TEST_CASE("Equality operators tests")
{
	String s1, s2;
	CHECK(s1 == s2);
	CHECK(s2 == s1);
	CHECK(s1.equals(s2));
	CHECK(s1.equalsIgnoreCase(s2));
	CHECK(s2.equals(s1));
	CHECK(s2.equalsIgnoreCase(s1));
	CHECK(!(s1 != s2));
	CHECK(s1 == nullptr);
	CHECK(s1.equals(nullptr));
	CHECK(s1.equalsIgnoreCase(nullptr));
	CHECK(!(s1 != nullptr));
	CHECK(s1 != ' ');
	CHECK(s1 != " ");
	CHECK(s1 == "");
	CHECK(s1.equals(""));
	CHECK(s1.equalsIgnoreCase(""));
	CHECK(' ' != s1);
	CHECK(" " != s1);
	CHECK("" == s1);

	s1 += 'f';
	CHECK(s1 != s2);
	CHECK(s2 != s1);
	CHECK(s1 == 'f');
	CHECK(s1.equals('f'));
	CHECK(s1.equalsIgnoreCase('f'));
	CHECK('f' == s1);

	s1 += "gg";
	String s3("fgg");
	CHECK(s1 == "fgg");
	CHECK(s1.equals("fgg"));
	CHECK("fgg" == s1);
	CHECK(s1 == s3);
	CHECK(s3 == s1);
	CHECK(s1.equals(s3));
	CHECK(s1.equalsIgnoreCase(s3));
	CHECK(s3.equals(s1));
	CHECK(s3.equalsIgnoreCase(s1));
	String s4("PesHO"), s5("pesho");
	CHECK(s4.equalsIgnoreCase(s5));
	CHECK(s5.equalsIgnoreCase(s4));
	s4 += "gosho";
	s5 += "GOSHO";
	CHECK(s4.equalsIgnoreCase(s5));
	CHECK(s5.equalsIgnoreCase(s4));
}

template <class T, class K>
void checkEqual(T s1, K s2)
{
	CHECK(!(s1 < s2));
	CHECK(!(s2 < s1));
	CHECK(!(s1 < s1));
	CHECK(!(s2 < s2));

	CHECK(!(s1 > s2));
	CHECK(!(s2 > s1));
	CHECK(!(s1 > s1));
	CHECK(!(s2 > s2));

	CHECK(s1 <= s2);
	CHECK(s2 <= s1);
	CHECK(s1 <= s1);
	CHECK(s2 <= s2);

	CHECK(s1 >= s2);
	CHECK(s2 >= s1);
	CHECK(s1 >= s1);
	CHECK(s2 >= s2);
}

TEST_CASE("Inequality operators tests (equal objects)")
{
	//test two strings
	String s1, s2;
	checkEqual(s1, s2);
	String s3(""), s4('\0');
	checkEqual(s3, s4);
	String s5, s6("\0");
	checkEqual(s5, s6);
	String s7("Gosho");
	String s8("Gosho");
	checkEqual(s7, s8);

	//test char array and string
	String s9("Pesho");
	checkEqual("Pesho", s9);
	checkEqual(s9, "Pesho");

	//test character and string
	String s10('m');
	checkEqual('m', s10);
	checkEqual(s10, 'm');
}

template <class T, class K>
void checkLess(T s1, K s2)
{
	CHECK(s1 < s2);
	CHECK(!(s2 < s1));
	CHECK(!(s1 < s1));
	CHECK(!(s2 < s2));

	CHECK(!(s1 > s2));
	CHECK(s2 > s1);
	CHECK(!(s1 > s1));
	CHECK(!(s2 > s2));

	CHECK(s1 <= s2);
	CHECK(!(s2 <= s1));
	CHECK(s1 <= s1);
	CHECK(s2 <= s2);

	CHECK(!(s1 >= s2));
	CHECK(s2 >= s1);
	CHECK(s1 >= s1);
	CHECK(s2 >= s2);
}

TEST_CASE("Inequality operators tests (a < b)")
{
	//test two strings
	String s1, s2("a");
	checkLess(s1, s2);
	String s3(""), s4('a');
	checkLess(s3, s4);
	String s5, s6("a");
	checkLess(s5, s6);
	String s7("Gosho");
	String s8("Goshoh");
	checkLess(s7, s8);

	//test char array and string
	String s9("bbc");
	checkLess("abc", s9);
	checkLess(s9, "bbcd");

	//test character and string
	String s10('z');
	checkLess('m', s10);
	String s11("agg");
	checkLess(s11, 'b');
}

template <class T, class K>
void checkGreater(T s1, K s2)
{
	CHECK(!(s1 < s2));
	CHECK(s2 < s1);
	CHECK(!(s1 < s1));
	CHECK(!(s2 < s2));

	CHECK(s1 > s2);
	CHECK(!(s2 > s1));
	CHECK(!(s1 > s1));
	CHECK(!(s2 > s2));

	CHECK(!(s1 <= s2));
	CHECK(s2 <= s1);
	CHECK(s1 <= s1);
	CHECK(s2 <= s2);

	CHECK(s1 >= s2);
	CHECK(!(s2 >= s1));
	CHECK(s1 >= s1);
	CHECK(s2 >= s2);
}

TEST_CASE("Inequality operators tests (a > b)")
{
	//test two strings
	String s1("abc"), s2("ab");
	checkGreater(s1, s2);
	String s3("ba"), s4('a');
	checkGreater(s3, s4);
	String s5("a"), s6;
	checkGreater(s5, s6);
	String s7("Goshoh");
	String s8("Gosho");
	checkGreater(s7, s8);

	//test char array and string
	String s9("abc");
	checkGreater("bbc", s9);
	checkGreater(s9, "aab");

	//test character and string
	String s10('b');
	checkGreater('m', s10);
	String s11("bgg");
	checkGreater(s11, 'b');
}

TEST_CASE("Addition operator tests")
{
	String s1, s2, s3;
	s3 = s1 + s2;
	CHECK(s3 == s1);
	CHECK(s3 == s2);

	s3 = s1 + 'm';
	s2 = 'm' + s1;
	CHECK(s3 == s2);
	CHECK(s1 == nullptr);

	s3 = s1 + "test";
	s2 = "test" + s1;
	CHECK(s3 == s2);
	CHECK(s1 == nullptr);

	String s4("yes");
	s3 = s4 + s1;
	s2 = s1 + s4;
	CHECK(s3 == s2);
	CHECK(s4 == "yes");
	CHECK(s1 == nullptr);

	s1 = s4 + s4 + s1 + s4;
	CHECK(s1 == "yesyesyes");
	s4 = s4 + s4 + s4;
	CHECK(s1 == s4);
	s4 += s4;
	s1 = s1 + s1;
	CHECK(s1 == s4);
}

TEST_CASE("Substring tests")
{
	String s1("Pesho");
	CHECK(s1.substring(0) == "Pesho");
	CHECK(s1.substring(1) == "esho");
	CHECK(s1.substring(4) == "o");
	CHECK(s1.substring(0, 5) == "Pesho");
	CHECK(s1.substring(2, 3) == "s");
	CHECK(s1.substring(1, 4) == "esh");
}

TEST_CASE("Starts with tests")
{
	String s1, s2;
	CHECK(s1.startsWith(""));
	CHECK(s1.startsWith(s2));
	CHECK(s1.startsWith("", 0));
	CHECK(s1.startsWith(s2, 0));
	s1 += "Pesho";
	s2 += "P";
	CHECK(s1.startsWith("P"));
	CHECK(s1.startsWith('P'));
	CHECK(s1.startsWith(s2));
	CHECK(s1.startsWith("Pesho"));
	CHECK(s1.startsWith("Pes"));
	s2 += "esh";
	CHECK(s1.startsWith(s2));
	CHECK(!(s1.startsWith("Peshos")));

	CHECK(s1.startsWith(s2, 0));
	CHECK(s1.startsWith('P', 0));
	CHECK(s1.startsWith("P", 0));
	CHECK(!(s1.startsWith(s2, 1)));
	CHECK(s1.startsWith("esho", 1));
	CHECK(s1.startsWith('e', 1));
	CHECK(s1.startsWith("e", 1));
	CHECK(s1.startsWith("o", 4));
	CHECK(s1.startsWith('o', 4));
	String s5('o');
	CHECK(s1.startsWith(s5, 4));
	CHECK(!s1.startsWith("Pes", 1));
}

TEST_CASE("Ends with tests")
{
	String s1, s2;
	CHECK(s1.endsWith(""));
	CHECK(s1.endsWith(s2));
	s1 += "Pesho";
	s2 += "o";
	CHECK(s1.endsWith("o"));
	CHECK(s1.endsWith('o'));
	CHECK(s1.endsWith(s2));
	CHECK(s1.endsWith("Pesho"));
	CHECK(s1.endsWith("sho"));
	s2 = "sh" + s2;
	CHECK(s1.endsWith(s2));
	CHECK(!(s1.endsWith("Peshos")));
}

TEST_CASE("Index of tests")
{
	String s1, s2;
	CHECK(s1.indexOf("") == -1);
	CHECK(s1.indexOf(s2) == -1);
	s1 += "Pesho";
	s2 += "P";
	CHECK(s1.indexOf("P") == 0);
	CHECK(s1.indexOf('P') == 0);
	CHECK(s1.indexOf(s2) == 0);
	CHECK(s1.indexOf("Pesho") == 0);
	CHECK(s1.indexOf("sho") == 2);
	CHECK(s1.indexOf("o") == 4);
	CHECK(s1.indexOf('o') == 4);
	String s3("o");
	CHECK(s1.indexOf(s3) == 4);
	CHECK(s1.indexOf("ho") == 3);
	CHECK(s1.indexOf("Peshos") == -1);
	CHECK(s1.indexOf("p") == -1);
	CHECK(s1.indexOf("s") == 2);

	String s4("PeshoGoshoMisho");
	CHECK(s4.indexOf("oGo", 4) == 4);
	CHECK(s4.indexOf("oGo", 5) == -1);
	CHECK(s4.indexOf("ho", 2) == 3);
	CHECK(s4.indexOf("ho", 4) == 8);
	CHECK(s4.indexOf("ho", 9) == 13);
	CHECK(s4.indexOf('o', 10) == 14);
	CHECK(s4.indexOf('P', 0) == 0);
	CHECK(s4.indexOf(s3, 5) == 6);
}

TEST_CASE("Last index of tests")
{
	String s1, s2;
	CHECK(s1.lastIndexOf("") == -1);
	CHECK(s1.lastIndexOf(s2) == -1);
	s1 += "ababababcd";
	CHECK(s1.lastIndexOf("ab") == 6);
	CHECK(s1.lastIndexOf("bab") == 5);
	CHECK(s1.lastIndexOf("abcd") == 6);
	CHECK(s1.lastIndexOf("ababababcd") == 0);
	CHECK(s1.lastIndexOf("d") == 9);
	CHECK(s1.lastIndexOf('a') == 6);
	CHECK(s1.lastIndexOf("ababababc") == 0);
	CHECK(s1.lastIndexOf("ababababcda") == -1);
	s2 += "ghhj";
	CHECK(s2.lastIndexOf("h") == 2);
	CHECK(s2.lastIndexOf("g") == 0);
	CHECK(s2.lastIndexOf("j") == 3);
	CHECK(s2.lastIndexOf("hh") == 1);
	s2 += "ghhj";
	CHECK(s2.lastIndexOf("ghhj") == 4);
	CHECK(s2.lastIndexOf("ggggggggghhj") == -1);
	CHECK(s2.lastIndexOf("ghhjghhj") == 0);
	CHECK(s2.lastIndexOf("ghhjghhjj") == -1);
	String s3("abcdefg");
	CHECK(s3.lastIndexOf("a") == 0);
	String s4("abcdcdabcd");
	CHECK(s4.lastIndexOf("ab", 3) == 0);
	CHECK(s4.lastIndexOf("ab", 1) == 0);
	CHECK(s4.lastIndexOf("a", 0) == 0);
	CHECK(s4.lastIndexOf('a', 0) == 0);
	CHECK(s4.lastIndexOf("ab", 7) == 6);
	CHECK(s4.lastIndexOf("abcd", 9) == 6);
	CHECK(s4.lastIndexOf("abcdcdabcd", 9) == 0);
	CHECK(s4.lastIndexOf("abcdcdabcdd", 9) == -1);
	CHECK(s4.lastIndexOf("d", 9) == 9);
	CHECK(s4.lastIndexOf('d', 9) == 9);
}

TEST_CASE("Contains tests")
{
	String s1;
	CHECK(!s1.contains(""));
	s1 += "abcdefg";
	CHECK(s1.contains("bcd"));
	CHECK(s1.contains("defg"));
	CHECK(s1.contains("abcdefg"));
	CHECK(!s1.contains("bce"));
	CHECK(s1.contains("g"));
	CHECK(s1.contains('a'));
}

TEST_CASE("To uppercase Tests")
{
	String s1, s2;
	CHECK(s1.toUpper() == "");
	s1 += "iJfmmnAAaak";
	s2 = s1.toUpper();
	CHECK(s2 == "IJFMMNAAAAK");
	CHECK(s1 == "iJfmmnAAaak");
	s1 += "123";
	s2 = s1.toUpper();
	CHECK(s2 == "IJFMMNAAAAK123");
	CHECK(s1 == "iJfmmnAAaak123");
}

TEST_CASE("To lowercase Tests")
{
	String s1, s2;
	CHECK(s1.toLower() == "");
	s1 += "iJfMMnAAaakZ";
	s2 = s1.toLower();
	CHECK(s2 == "ijfmmnaaaakz");
	CHECK(s1 == "iJfMMnAAaakZ");
	s1 += "123";
	s2 = s1.toLower();
	CHECK(s2 == "ijfmmnaaaakz123");
	CHECK(s1 == "iJfMMnAAaakZ123");
}

TEST_CASE("Replace Tests")
{
	String s1("aaaaa");
	CHECK(s1.replace("aa", "b") == "bba");
	CHECK(s1.replace("aa", "bbbbbbb") == "bbbbbbbbbbbbbba");
	CHECK(s1.replace('a', 'b') == "bbbbb");
	CHECK(s1.replace("aaaa", "cbdav") == "cbdava");
	CHECK(s1.replace("aaaaa", "") == "");
	CHECK(s1.replace("a", "") == "");
	CHECK(s1 == "aaaaa");
	String s2("abababbacd");
	CHECK(s2.replace("ab", "") == "bacd");
	CHECK(s2.replace("ba", "ba") == "abababbacd");
	CHECK(s2.replace("cd", "") == "abababba");
	CHECK(s2.replace("a", "c") == "cbcbcbbccd");
	CHECK(s2.replace("a", "jjjjjjjjjjj") == "jjjjjjjjjjjbjjjjjjjjjjjbjjjjjjjjjjjbbjjjjjjjjjjjcd");
	String s3;
	CHECK(s3.replace("", "Pesho") == "");
	CHECK(s2.replace("", "Pesho") == s2);
}

TEST_CASE("Replace First Tests")
{
	String s1("aaaaa");
	CHECK(s1.replaceFirst("aa", "b") == "baaa");
	CHECK(s1.replaceFirst("aa", "bbbbbbb") == "bbbbbbbaaa");
	CHECK(s1.replaceFirst('a', 'b') == "baaaa");
	CHECK(s1.replaceFirst("aaaa", "cbdav") == "cbdava");
	CHECK(s1.replaceFirst("aaaaa", "") == "");
	CHECK(s1.replaceFirst("a", "") == "aaaa");
	CHECK(s1 == "aaaaa");
	String s2("abababbacd");
	CHECK(s2.replaceFirst("ab", "") == "ababbacd");
	CHECK(s2.replaceFirst("ba", "ba") == "abababbacd");
	CHECK(s2.replaceFirst("cd", "") == "abababba");
	CHECK(s2.replaceFirst("a", "c") == "cbababbacd");
	CHECK(s2.replaceFirst("a", "jjjjjjjjjjj") == "jjjjjjjjjjjbababbacd");
	String s3;
	CHECK(s3.replaceFirst("", "Pesho") == "");
	CHECK(s2.replaceFirst("", "Pesho") == s2);
}

TEST_CASE("Replace Last Tests")
{
	String s1("aaaaa");
	CHECK(s1.replaceLast("aa", "b") == "aaab");
	CHECK(s1.replaceLast("aa", "bbbbbbb") == "aaabbbbbbb");
	CHECK(s1.replaceLast('a', 'b') == "aaaab");
	CHECK(s1.replaceLast("aaaa", "cbdav") == "acbdav");
	CHECK(s1.replaceLast("aaaaa", "") == "");
	CHECK(s1.replaceLast("a", "") == "aaaa");
	CHECK(s1 == "aaaaa");
	String s2("abababbacd");
	CHECK(s2.replaceLast("ab", "") == "ababbacd");
	CHECK(s2.replaceLast("ba", "ba") == "abababbacd");
	CHECK(s2.replaceLast("cd", "") == "abababba");
	CHECK(s2.replaceLast("a", "c") == "abababbccd");
	CHECK(s2.replaceLast("a", "jjjjjjjjjjj") == "abababbjjjjjjjjjjjcd");
	String s3;
	CHECK(s3.replaceLast("", "Pesho") == "");
	CHECK(s2.replaceLast("", "Pesho") == s2);
}

TEST_CASE("Trim start Tests")
{
	String s1("   abcdefgh");
	CHECK(s1.trimStart() == "abcdefgh");
	s1 = s1.trimStart();
	CHECK(s1 == "abcdefgh");
	s1 = "  " + s1;
	CHECK(s1.trimStart() == "abcdefgh");
	s1 = " j s b m d";
	CHECK(s1.trimStart() == "j s b m d");
	s1 = "      ";
	CHECK(s1.trimStart() == "");
	s1 = "";
	CHECK(s1.trimStart() == "");
	s1 += "     a";
	CHECK(s1.trimStart() == "a");
}

TEST_CASE("Trim end Tests")
{
	String s1("abcdefgh   ");
	CHECK(s1.trimEnd() == "abcdefgh");
	s1 = s1.trimEnd();
	CHECK(s1 == "abcdefgh");
	s1 += "  ";
	CHECK(s1.trimEnd() == "abcdefgh");
	s1 = " j s b m d  ";
	CHECK(s1.trimEnd() == " j s b m d");
	s1 = "      ";
	CHECK(s1.trimEnd() == "");
	s1 = "";
	CHECK(s1.trimEnd() == "");
	s1 += "b      ";
	CHECK(s1.trimEnd() == "b");
}

TEST_CASE("Trim Tests")
{
	String s1("       abcdefgh   ");
	CHECK(s1.trim() == "abcdefgh");
	s1 = s1.trim();
	CHECK(s1 == "abcdefgh");
	s1 += "  ";
	CHECK(s1.trim() == "abcdefgh");
	s1 = " j s b m d  ";
	CHECK(s1.trim() == "j s b m d");
	s1 = "      ";
	CHECK(s1.trim() == "");
	s1 = "";
	CHECK(s1.trim() == "");
	s1 += "b      ";
	CHECK(s1.trim() == "b");
	s1 = "         b";
	CHECK(s1.trim() == "b");
	s1 = "   fjs slk js   s ";
	CHECK(s1.trim() == "fjs slk js   s");
}

int main()
{
	doctest::Context().run();

	return 0;
}
