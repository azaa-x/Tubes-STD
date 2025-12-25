#include "Product.h"
#include <iostream>
using namespace std;

int main() {
    adrNode root = nullptr;
    int pilihan;

    do {
        cout << "\n=== MENU PRODUCT BST ===\n";
        cout << "1. Tambah Produk\n";
        cout << "2. Hapus Produk\n";
        cout << "3. Tampilkan Produk (Inorder)\n";
        cout << "4. Tampilkan Produk (Preorder)\n";
        cout << "5. Tampilkan Produk (Postorder)\n";
        cout << "6. Tampilkan Produk Min/Max\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                string name;
                int jumlah;

                cout << "Nama Produk: ";
                cin >> name;
                cout << "Jumlah Penjualan: ";
                cin >> jumlah;

                insertProduct(root, createNode(name, jumlah));
                break;
            }
            case 2: {
                int jumlah;
                cout << "Masukkan jumlah penjualan produk yang ingin dihapus: ";
                cin >> jumlah;
                root = deleteNode(root, jumlah);
                break;
            }
            case 3: {
                cout << "\n=== Inorder Traversal ===\n";
                inOrder(root);
                break;
            }
            case 4: {
                cout << "\n=== Preorder Traversal ===\n";
                preOrder(root);
                break;
            }
            case 5: {
                cout << "\n=== Postorder Traversal ===\n";
                postOrder(root);
                break;
            }
            case 6: {
                if (root == nullptr) {
                    cout << "Tree kosong!\n";
                } else {
                    int minJumlah = getMinValue(root);
                    int maxJumlah = getMaxValue(root);

                    adrNode minNode = searchProduct(root, minJumlah);
                    adrNode maxNode = searchProduct(root, maxJumlah);

                    cout << "\nProduk dengan jumlah penjualan MIN: "
                         << minNode->name << " (" << minNode->jumlah << ")\n";
                    cout << "Produk dengan jumlah penjualan MAX: "
                         << maxNode->name << " (" << maxNode->jumlah << ")\n";
                }
                break;
            }
            case 0: {
                cout << "Keluar...\n";
                break;
            }
            default: {
                cout << "Pilihan tidak tersedia!\n";
                break;
            }
        }

    } while (pilihan != 0);

    return 0;
}
