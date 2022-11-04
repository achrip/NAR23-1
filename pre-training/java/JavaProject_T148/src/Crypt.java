import javax.crypto.Cipher;
import javax.crypto.SecretKey;
import javax.crypto.SecretKeyFactory;
import javax.crypto.spec.GCMParameterSpec;
import javax.crypto.spec.PBEKeySpec;
import javax.crypto.spec.SecretKeySpec;
import java.security.SecureRandom;
import java.security.spec.KeySpec;
import java.util.Base64;

public class Crypt {
    private Cipher cipher;
    private static SecretKeySpec key;

//    private String encode(byte[] data){
//        return Base64.getEncoder().encodeToString(data);
//    }
//    private byte[] decode(String data){
//        return Base64.getDecoder().decode(data);
//    }
//
//    private void initKey() throws Exception{
//        byte[] salt = new byte[8];
//        new SecureRandom().nextBytes(salt);
//        SecretKeyFactory keyFactory = SecretKeyFactory.getInstance("PBKDF2WithHmacSHA1");
//        KeySpec spec = new PBEKeySpec("Us3rS3CR3TD4T4SS".toCharArray(), salt, 100, 120);
//        SecretKey tmp = keyFactory.generateSecret(spec);
//        SecretKeySpec key = new SecretKeySpec(tmp.getEncoded(), "AES");
//    }
//        public String encrypt(String item) throws Exception{
//        byte[] salt = new byte[8];
//        new SecureRandom().nextBytes(salt);
//        SecretKeyFactory keyFactory = SecretKeyFactory.getInstance("PBKDF2WithHmacSHA1");
//        KeySpec spec = new PBEKeySpec("Us3rS3CR3TD4T4SS".toCharArray(), salt, 100, 120);
//        SecretKey tmp = keyFactory.generateSecret(spec);
//        SecretKeySpec key = new SecretKeySpec(tmp.getEncoded(), "AES");
//
//        byte[] byteItem = item.getBytes();
//        cipher = Cipher.getInstance("AES/CBC/PKCS5Padding");
//        cipher.init(Cipher.ENCRYPT_MODE, key);
//        byte[] encryptedBytes = cipher.doFinal(byteItem);
//        return encode(encryptedBytes);
//    }
//
//    public String decrypt(String cryptItem) throws Exception{
//        byte[] byteItem = decode(cryptItem);
//        cipher = Cipher.getInstance("AES/CBC/PKCS5Padding");
//        cipher.init(Cipher.DECRYPT_MODE, key);
//        byte[] decryptedBytes = cipher.doFinal(byteItem);
//        return new String(decryptedBytes);
//    }

        public static void main(String[] args) {

            try {
                byte[] salt = new byte[8];
                new SecureRandom().nextBytes(salt);

                SecretKeyFactory keyFactory = SecretKeyFactory.getInstance("PBKDF2WithHmacSHA1");
                KeySpec keySpec = new PBEKeySpec("myPassword".toCharArray(), salt, 100, 128);

                SecretKey tmp = keyFactory.generateSecret(keySpec);
                key = new SecretKeySpec(tmp.getEncoded(), "AES");

                Cipher enCipher = Cipher.getInstance("AES/GCM/NoPadding");
                enCipher.init(Cipher.ENCRYPT_MODE, key);

                // enCipher.init(Cipher.ENCRYPT_MODE, key, new IvParameterSpec(iv));

                byte[] cipherBytes = enCipher.doFinal("myMessage;myRegards".getBytes());
                Base64.Encoder encoder = Base64.getEncoder();
                String cipherMsg = encoder.encodeToString(cipherBytes);

                System.out.println("Encrypted message: " + cipherMsg);

                Base64.Decoder decoder = Base64.getDecoder();
                byte[] decodedByte = decoder.decode(cipherMsg);
                Cipher deCipher = Cipher.getInstance("AES/GCM/NoPadding");
                GCMParameterSpec gmcSpec = new GCMParameterSpec(128, enCipher.getIV());
                deCipher.init(Cipher.DECRYPT_MODE, key, gmcSpec);
                byte[] decipherByte = deCipher.doFinal(decodedByte);
                String decipherMsg = new String(decipherByte);

                System.out.println("Decrypted text: " + decipherMsg);



            } catch (Exception ex) {
                ex.printStackTrace();
            }

        }
}