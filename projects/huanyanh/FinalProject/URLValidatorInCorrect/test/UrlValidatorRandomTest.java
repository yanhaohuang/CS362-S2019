import junit.framework.TestCase;
import java.util.concurrent.ThreadLocalRandom;

public class UrlValidatorRandomTest extends TestCase {

	public void testRandomValidator() {
		long options = UrlValidator.ALLOW_2_SLASHES + UrlValidator.ALLOW_ALL_SCHEMES + UrlValidator.NO_FRAGMENTS;

		UrlValidator validator = new UrlValidator(null, null, options);

		// Result pair URL parts adapted from UrlValidatorTest
		ResultPair[] testUrlSchemes = { new ResultPair("http://", true), new ResultPair("ftp://", true),
				new ResultPair("h3t://", true), new ResultPair("3ht://", false), new ResultPair("http:/", false),
				new ResultPair("http:", false), new ResultPair("http/", false), new ResultPair("://", false) };

		ResultPair[] testUrlAuthorities = { new ResultPair("www.google.com", true),
				new ResultPair("www.google.com.", true), new ResultPair("go.com", true), new ResultPair("go.au", true),
				new ResultPair("0.0.0.0", true), new ResultPair("255.255.255.255", true),
				new ResultPair("256.256.256.256", false), new ResultPair("255.com", true),
				new ResultPair("1.2.3.4.5", false), new ResultPair("1.2.3.4.", false), new ResultPair("1.2.3", false),
				new ResultPair(".1.2.3.4", false), new ResultPair("go.a", false), new ResultPair("go.a1a", false),
				new ResultPair("go.cc", true), new ResultPair("go.1aa", false), new ResultPair("aaa.", false),
				new ResultPair(".aaa", false), new ResultPair("aaa", false), new ResultPair("", false) };

		ResultPair[] testUrlPorts = { new ResultPair(":80", true), new ResultPair(":65535", true), // max possible
				new ResultPair(":65536", false), // max possible +1
				new ResultPair(":0", true), new ResultPair("", true), new ResultPair(":-1", false),
				new ResultPair(":65636", false), new ResultPair(":999999999999999999", false),
				new ResultPair(":65a", false) };

		ResultPair[] testUrlPaths = { new ResultPair("/test1", true), new ResultPair("/t123", true),
				new ResultPair("/$23", true), new ResultPair("/..", false), new ResultPair("/../", false),
				new ResultPair("/test1/", true), new ResultPair("", true), new ResultPair("/test1/file", true),
				new ResultPair("/..//file", false), new ResultPair("/test1//file", true) };

		ResultPair[] testUrlPathOptions = { new ResultPair("/test1", true), new ResultPair("/t123", true),
				new ResultPair("/$23", true), new ResultPair("/test1/", true), new ResultPair("/#", false),
				new ResultPair("", true), new ResultPair("/test1/file", true), new ResultPair("/t123/file", true),
				new ResultPair("/$23/file", true), new ResultPair("/test1//file", true),
				new ResultPair("/#/file", false) };

		ResultPair[] testUrlQueries = { new ResultPair("?action=view", true),
				new ResultPair("?action=edit&mode=up", true), new ResultPair("", true) };

		// Select a random URL portion for each to construct a URL, and check expected
		// validity for each portion to get expected validity of that URL
		for (int i = 0; i < 25000; i++) {
			boolean expectedIsValid = true;

			int randScheme = ThreadLocalRandom.current().nextInt(0, testUrlSchemes.length);
			String constructedUrl = testUrlSchemes[randScheme].item;
			expectedIsValid = testUrlSchemes[randScheme].valid && expectedIsValid;

			int randAuthority = ThreadLocalRandom.current().nextInt(0, testUrlAuthorities.length);
			constructedUrl += testUrlAuthorities[randAuthority].item;
			expectedIsValid = testUrlAuthorities[randAuthority].valid && expectedIsValid;

			int randPort = ThreadLocalRandom.current().nextInt(0, testUrlPorts.length);
			constructedUrl += testUrlPorts[randPort].item;
			expectedIsValid = testUrlPorts[randPort].valid && expectedIsValid;

			int randPath = ThreadLocalRandom.current().nextInt(0, testUrlPaths.length);
			constructedUrl += testUrlPaths[randPath].item;
			expectedIsValid = testUrlPaths[randPath].valid && expectedIsValid;

			int randPathOption = ThreadLocalRandom.current().nextInt(0, testUrlPathOptions.length);
			constructedUrl += testUrlPathOptions[randPathOption].item;
			expectedIsValid = testUrlPathOptions[randPathOption].valid && expectedIsValid;

			int randQuery = ThreadLocalRandom.current().nextInt(0, testUrlQueries.length);
			constructedUrl += testUrlQueries[randQuery].item;
			expectedIsValid = testUrlQueries[randQuery].valid && expectedIsValid;
			int iterationCounter = i + 1;
			System.out.println("Iteration " + iterationCounter);

			if (expectedIsValid) {
				System.out.println("Expect is valid");
				System.out.println(constructedUrl);
				if (!validator.isValid(constructedUrl)) {
					boolean test = validator.isValid(constructedUrl);
					System.out.println(test);
				}
				assertTrue(validator.isValid(constructedUrl));
			} else {
				System.out.println("Expect is NOT valid");
				System.out.println(constructedUrl);
				if (validator.isValid(constructedUrl)) {
					boolean test = validator.isValid(constructedUrl);
					System.out.println(test);
				}
				assertFalse(validator.isValid(constructedUrl));
			}
		}
	}
}
