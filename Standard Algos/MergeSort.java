/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication1;

/**
 *
 * @author monishg
 */
public class JavaApplication1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        //Test Cases:
        //duplicate elements
        int[] list = new int[]{9, 8, 1, 5, 2, 2, 5, 6, 4, 0};
        Sort.mergeSort(list, 0, list.length - 1);
        assert Sort.isSorted(list, 0, list.length - 1, Sort.ORDER.ASCENDING);
        System.out.println("Done");

        //unique set of elements
        list = new int[]{9, 8, 1, 5, 2, 6, 4, 0, -5, -9};
        Sort.mergeSort(list, 0, list.length - 1);
        assert Sort.isSorted(list, 0, list.length - 1, Sort.ORDER.ASCENDING);
        System.out.println("Done");

        //zero elements
        list = new int[0];
        Sort.mergeSort(list, 0, list.length - 1);
        assert Sort.isSorted(list, 0, list.length - 1, Sort.ORDER.ASCENDING);
        System.out.println("Done");

        //end = beg
        list = new int[]{9, 8, 1, 5, 2, 2, 5, 6, 4, 0};
        int[] origList = new int[list.length];
        System.arraycopy(list, 0, origList, 0, list.length);
        System.out.println("Done");

        Sort.mergeSort(list, 5, 5);
        assert isEqual(list, origList, /*from*/ 0, /*to*/ 4);
        assert isEqual(list, origList, /*from*/ 6, /*to*/ list.length - 1);
        System.out.println("Done");

        //test that only elements in beg to end are changed
        list = new int[]{9, 8, 1, 5, 2, 2, 5, 6, 4, 0};
        origList = new int[list.length];
        System.arraycopy(list, 0, origList, 0, list.length);
        System.out.println("Done");

        Sort.mergeSort(list, 3, 6);
        assert isEqual(list, origList, /*from*/ 1, /*to*/ 2);
        assert isEqual(list, origList, /*from*/ 7, /*to*/ list.length - 1);
        System.out.println("Done");
    }

    private static boolean isEqual(int[] list, int[] origList, int i, int i0) {
        for (; i <= i0; i++) {
            assert list[i] == origList[i];
        }
        return true;
    }
}

class Sort {

    static boolean isSorted(int[] list, int i, int i0, Sort.ORDER order) {
        assert i >= 0 && i <= i0 && i0 < list.length;
        for (; i < i0; i++) {
            if (order == Sort.ORDER.ASCENDING) {
                assert list[i] <= list[i + 1];
            } else {
                assert list[i] >= list[i + 1];
            }
        }
        return true;
    }

    public static enum ORDER {

        ASCENDING, DESCENDING
    };

    //Sorts the part of int[] list starting from int beg till int end.
    public static void mergeSort(int[] list, int beg, int end) {
        if (end - beg <= 1) {
            return;
        }
        int mid = (end + beg) / 2;
        mergeSort(list, beg, mid);
        mergeSort(list, mid + 1, end);
        merge(list, beg, mid, mid + 1, end);
    }

    //Merges two non-overlapping parts of int[].
    private static void merge(int[] list, int beg1, int end1, int beg2, int end2) {
        assert (beg1 <= end1 && end1 < beg2 && beg2 <= end2);
        int[] mergedList = new int[end1 - beg1 + 1 + end2 - beg2 + 1];
        int mergedListIndex = 0;
        while (beg1 <= end1 && beg2 <= end2) {
            if (list[beg1] <= list[beg2]) {
                mergedList[mergedListIndex++] = list[beg1++];
            } else {
                mergedList[mergedListIndex++] = list[beg2++];
            }
        }
        int beg = beg1, end = end1;
        if (beg2 <= end2) {
            assert (beg1 > end1);
            beg = beg2;
            end = end2;
        }
        while (beg <= end) {
            mergedList[mergedListIndex++] = list[beg++];
        }
    }
}