#include "Product.h"
#include <iostream>>

using namespace std;

int main() {
    adrNode root = nullptr;
    int pilihan;

    do {
        cout << "\n=== MENU PRODUCT MARKETPLACE (BST) ===\n";
        cout << "1. Tambah Produk\n";
        cout << "2. Hapus Produk\n";
        cout << "3. Tampilkan Inorder\n";
        cout << "4. Tampilkan Preorder\n";
        cout << "5. Tampilkan Postorder\n";
        cout << "6. Cari Produk\n";
        cout << "7. Tampilkan Nilai Penjualan Minimum dan Maksimum\n";
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
                cout << "Produk berhasil ditambahkan! " << endl;
                break;
            }

            case 2: {
                int jumlah;
                cout << "Masukkan jumlah penjualan yang dihapus: ";
                cin >> jumlah;
                root = deleteNode(root, jumlah);
                cout << "Data berhasil diproses\n";
                break;
            }

            case 3:
                cout << "\n--- Inorder Traversal ---\n";
                inOrder(root);
                break;

            case 4:
                cout << "\n--- Preorder Traversal ---\n";
                preOrder(root);
                break;

            case 5:
                cout << "\n--- Postorder Traversal ---\n";
                postOrder(root);
                break;

            case 6: {
                int jumlah;
                cout << "Cari jumlah penjualan: ";
                cin >> jumlah;
                adrNode hasil = searchProduct(root, jumlah);
                if (hasil != nullptr) {
                    cout << "Produk ditemukan\n";
                    cout << "Nama   : " << hasil->name << endl;
                    cout << "Jumlah : " << hasil->jumlah << endl;
                } else {
                    cout << "Produk tidak ditemukan\n";
                }
                break;
            }

            case 7:
                if (root == nullptr) {
                    cout << "Tree masih kosong\n";
                } else {
                    cout << "Penjualan Minimum : "
                         << getMinValue(root) << endl;
                    cout << "Penjualan Maksimum: "
                         << getMaxValue(root) << endl;
                }
                break;

            case 0:
                cout << "Keluar...\n";
                break;

            default:
                cout << "Pilihan salah!\n";
        }

    } while (pilihan != 0);

    return 0;
}
