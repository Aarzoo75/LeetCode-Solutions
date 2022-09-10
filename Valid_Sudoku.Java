class Solution {
    public boolean isValidSudoku(char[][] board) {

        for(int i = 0; i< 9; i++) {
            int[] col = new int[]{0,0,0,0,0,0,0,0,0,0};
            int[] row = new int[]{0,0,0,0,0,0,0,0,0,0};
            int[] box = new int[]{0,0,0,0,0,0,0,0,0,0};
            for(int j=0; j<9; j++) {
				// basically this is where the box has to be wrapped. 
				// If we try to put down the math here, the modulii operation will lead to us going from 
				// top most box to the left then wrap down and finally till the bottom.
                char boxC = board[(i/3)*3+j/3][(i%3)*3+j%3];
                char rowC = board[i][j];
                char colC = board[j][i];
                if(boxC != '.') {
                    box[ boxC - '0'] +=1;
                }
                if(rowC != '.') {
                    row[ rowC - '0'] +=1;
                }

                if(colC != '.') {
                    col[ colC - '0'] +=1;
                }
            }
			// After adding everything to the count, we verify if any count within this has exceeded 1.
            for(int j=0; j<=9; j++) {
                boolean valid = valid(box[j]) && valid(row[j]) && valid(col[j]);
                if(!valid)
                    return false;
            }
        }
        return true;
    }
    
    private boolean valid(int count) {
        return count==0 || count ==1;
    }
}
