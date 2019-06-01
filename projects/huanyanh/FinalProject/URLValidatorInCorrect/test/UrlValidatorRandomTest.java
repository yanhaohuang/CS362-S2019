import junit.framework.TestCase;

//** TODO Modify function below to random tests 
public class UrlValidatorRandomTest extends TestCase {

   public void testValidator() {
		UrlValidator validator = new UrlValidator();
		String[] valid = new String[15];
		String[] invalid = new String[15];

		valid[0] = "http://www.google.com";
		valid[1] = "http://255.com:80";
		valid[2] = "http://go.com";
		valid[3] = "http://go.au/$23";
		valid[4] = "http://0.0.0.0:65535/test1";
		valid[5] = "http://www.cnn.com/WORLD/?hpt=sitenav";
		valid[6] = "http://www.cnn.com./WORLD/?hpt=sitenav";
		valid[7] = "http://example.rocks:/";
		valid[8] = "http://hello.tokyo/";
		valid[9] = "http://www.example.org/a/b/hello..world";
		valid[10] = "http://www.example.org/a/hello..world";
		valid[11] = "http://www.apache.org:80/path";
		valid[12] = "http://user:pass@www.apache.org:80/path";
		valid[13] = "http://us%00er:-._~!$&'()*+,;=@www.apache.org:80/path";
		valid[14] = "http://example.com/serach?address=Main%20Avenue";

		invalid[0] = "http/www.google.com";
		invalid[1] = "http://go.com/test1//file";
		invalid[2] = "ftp://255.com:65636";
		invalid[3] = "://go.au/t123/file";
		invalid[4] = "http://1.2.3.4.5";
		invalid[5] = "http://www.cnn.com../";
		invalid[6] = "http://www.cnn.invalid/";
		invalid[7] = "http://example.rocks:65536/";
		invalid[8] = "http://example.rocks:100000/";
		invalid[9] = "http://www.example.org/../world";
		invalid[10] = "http://:pass@www.apache.org:80/path";
		invalid[11] = "http://:@www.apache.org:80/path";
		invalid[12] = "http://:@www.apache.org:80/path";
		invalid[13] = "http://user:pa:ss@www.apache.org/path";
		invalid[14] = "http://example.com/serach?address=Main Avenue";

		for (int i = 0; i < 15; i++) {
			assertTrue(validator.isValid(valid[i]));
		}

		for (int i = 0; i < 15; i++) {
			assertFalse(validator.isValid(invalid[i]));
		}
   }
}
