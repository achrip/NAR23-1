import javax.crypto.Cipher;
import javax.crypto.spec.GCMParameterSpec;
import javax.crypto.spec.SecretKeySpec;
import java.util.Base64;

public class Crypt {

    protected final byte[] key = "Us3rS3CR3TD4T4SS".getBytes();
    private String s;
    private Cipher cipher;

    private String encode(byte[] data){
        return Base64.getEncoder().encodeToString(data);
    }

    private byte[] decode(String data){
        return Base64.getDecoder().decode(data);
    }

    public String encrypt(String item) throws Exception{
        SecretKeySpec keySpec = new SecretKeySpec(key, "AES");

        byte[] byteItem = item.getBytes();
        cipher = Cipher.getInstance("AES/ECB/NoPadding");
        cipher.init(Cipher.ENCRYPT_MODE, keySpec);
        byte[] encryptedBytes = cipher.doFinal(byteItem);
        return encode(encryptedBytes);

    }

    public String decrypt(String cryptItem) throws Exception{
        byte[] secretKey = new byte[16] ;
        Base64.getDecoder().decode(key, secretKey);
        SecretKeySpec keySpec = new SecretKeySpec(secretKey,"AES");

        byte[] byteItem = Base64.getDecoder().decode(cryptItem);
        cipher = Cipher.getInstance("AES/ECB/PKCS5Padding");
        cipher.init(Cipher.DECRYPT_MODE, keySpec);
        byte[] decryptedBytes = cipher.doFinal(byteItem);
        return new String(decryptedBytes);
    }
}