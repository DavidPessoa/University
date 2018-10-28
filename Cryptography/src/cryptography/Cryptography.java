
package cryptography;

/**
 *
 * @author David
 */
public class Cryptography {

    private String[][] m;
    static  int[] sbox = {0x9, 0x4, 0xA, 0xB, 0xD, 0x1, 0x8, 0x5, 0x6, 0x2, 0x0, 0x3, 0xC, 0xE, 0xF, 0x7};  
    static  int[] sboxi = {0xa, 0x5, 0x9, 0xb, 0x1, 0x7, 0x8, 0xf, 0x6, 0x0, 0x2, 0x3, 0xc, 0x4, 0xd, 0xe};
    public static int[][] shiftRows(int[][] state) {
       int [][] newState = new int [2][2];
       newState[0][0] = state [0][0];
       newState[1][1] = state [0][1];
       newState[1][0] = state [1][0];
       newState[0][1] = state [1][1];
       return newState;  
    }

    public static int[] keyExpantion(int cipherKey) {
        int w0 = cipherKey >> 8;
        int w1 = (w0 << 8) ^ cipherKey;
        int w2 = w0 ^ 0b10000000 ^ invNibbles(w1);
        int w3 = w2 ^ w1;
        int w4 = (w2 ^ 0b00110000) ^ invNibbles(w3);
        int w5 = w4 ^ w3;
        int key0 = w0 << 8;
        key0 = key0 ^ w1;
        int key1 = w2 << 8;
        key1 = key1 ^ w3;
        int key2 = w4 << 8;
        key2 = key2 ^ w5;

        int[] finalReply = {key0, key1, key2};
        return finalReply;

    }

    public static int addRoundKey(int key, int plaintext) {
        return key ^ plaintext;
    }

    public static int subNibbles(int nibles) {
        int result;
       
        int[] index = {0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xA, 0xB, 0xC, 0xD, 0xE, 0xF};

        for (int i = 0; i < 16; i++) {
            if (nibles == index[i]) {
                return sbox[i];
            }
        }
        return -1;
    }

    public static int[][] putInMatrix(int number){
      int matrix [][] = new int [2][2];
      matrix[0][0] = number >>12 ;
      matrix[0][1] = (number >> 8) & 0xf;
      matrix[1][0] = (number >> 4) & 0xf;
      matrix[1][1] = number & 0xf;
             
      return matrix;
    }
    
    public static int putInNumeric(int [][] matrix){
        int number = (matrix[0][0]<<12)^(matrix[0][1]<<8)^(matrix[1][0]<<4)^matrix[1][1];
        return number;
    }
    
    // Inverts Nibbles and calls subNibbles function to do the replacement
    public static int invNibbles(int nibbles) {
        int result = nibbles >> 4;
        int rightNibbles;
        result = result << 4;
        rightNibbles = (result ^ nibbles);
        rightNibbles = subNibbles(rightNibbles);
        result = result >> 4;
        result = subNibbles(result);
        rightNibbles = rightNibbles << 4;
        result = rightNibbles ^ result;
        return result;

    }
    
    public static int[][] mixColumns(int[][] state){
        int [][] result = new int [2][2];
        result[0][0] = state[0][0] ^ mult(4,state [0][1]);
        result[0][1] = state[0][1] ^ mult(4,state [0][0]);
        result[1][0] = state[1][0] ^ mult(4,state [1][1]);
        result[1][1] = state[1][1] ^ mult(4,state [1][0]);
        return result;
    }
    
    public static int[][] invMixColumns(int[][] state){
        int [][] result = new int [2][2];
        result[0][0] = mult(9,state[0][0]) ^ mult(2,state [0][1]);     
        result[0][1] = mult(2,state[0][0]) ^ mult(9,state [0][1]);
        result[1][0] = mult(9,state[1][0]) ^ mult(2,state [1][1]);
        result[1][1] = mult(2,state[1][0]) ^ mult(9,state [1][1]);
        return result;
    }

    
    public static int mult(int p1, int p2){
    int  p = 0;
    while (p2 > 0){
        if ((p2 & 0b1) > 0){
            p ^= p1;
        }
        p1 <<= 1;
        if ((p1 & 0b10000) > 0){
            p1 ^= 0b11; 
        }
        p2 >>= 1;
    
            }
    return p & 0b1111;	
    }
    
    public static int subBytes(int number) {
      int matrix [][] = new int [2][2];
      int result;
      matrix[0][0] = sbox[number >>12] ;
      matrix[0][1] = sbox[(number >> 8) & 0xf];
      matrix[1][0] = sbox[(number >> 4) & 0xf];
      matrix[1][1] = sbox[number & 0xf];
      
     result = putInNumeric(matrix);
     return result;
    }

     public static int invSubBytes(int number) {
      int matrix [][] = new int [2][2];
      int result;
      matrix[0][0] = sboxi[number >>12] ;
      matrix[0][1] = sboxi[(number >> 8) & 0xf];
      matrix[1][0] = sboxi[(number >> 4) & 0xf];
      matrix[1][1] = sboxi[number & 0xf];
     result = putInNumeric(matrix);
     return result;
    }

     
    public static void encrypt(int cipherKey, int plaintext){
        int [] roundkeys = keyExpantion(cipherKey);
        int state = addRoundKey(roundkeys[0],plaintext);
        state = subBytes(state);
        state = putInNumeric(mixColumns(shiftRows(putInMatrix(state))));
        state = subBytes(addRoundKey(roundkeys[1], state));
        state = putInNumeric(shiftRows(putInMatrix(state)));
        state = addRoundKey(roundkeys[2],state);
        System.out.println("Your ciphertext is: "+ Integer.toBinaryString( state ));
    }
    
    public static void decrypt(int cipherKey, int ciphertext){
        int [] roundkeys = keyExpantion(cipherKey);
        int state = addRoundKey(roundkeys[2],ciphertext);
        state = putInNumeric(shiftRows(putInMatrix(state)));
        state = invSubBytes(state);
        state = addRoundKey(roundkeys[1],state);
        state = putInNumeric(shiftRows(invMixColumns(putInMatrix(state))));
        state = invSubBytes(state);
        state = addRoundKey(roundkeys[0],state);
        System.out.println("Your plaintext is: "+ Integer.toBinaryString( state ));
        
    }
    
    public static void main(String[] args) {
        /* Another example
        plaintext = 0b0110111101101011;
        cipherkey = 0b1010 0111 00111011;  
        */
        int plaintext = 0b1101011100101000;
        int cipherKey = 0b0100101011110101;
        int ciphertext = 0b0010010011101100;
        
        encrypt(cipherKey, plaintext);
        decrypt(cipherKey, ciphertext);
        
    }

}
