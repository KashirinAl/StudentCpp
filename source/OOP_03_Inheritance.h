// ��������������� ����:
// ������������

#pragma once
#include <iostream>
using namespace std;

namespace Inheritance
{
   class Parent
   {
      int parentPrivate;
   protected:
      int parentProtected;
   public:
      int parentPublic;
   };

   class ChildPrivate : Parent
   {
   public:
      ChildPrivate() : Parent() // ������������� �������� ����������� ������������� ������
      {
         // parentPrivate = 0; // ����������
         parentProtected = 1;
         parentPublic = 2;
      }
   };

   class ChildProtected : protected Parent
   {
   public:
      ChildProtected() : Parent()
      {
         // parentPrivate = 0; // ����������
         parentProtected = 1;
         parentPublic = 2;
      }
   };

   class ChildPublic : public Parent
   {
   public:
      ChildPublic() : Parent()
      {
         // parentPrivate = 0; // ����������
         parentProtected = 1;
         parentPublic = 2;
      }
   };

   /*
    * ������� ��������� ����������� ����� ��� ��������� ������������� ������������:
    * 
    * 
    * |  �����������    |       ����������� ������������    |
    * |  ��������� �    |-----------------------------------|
    * |  ������� ������ |   public  | protected |  private  |
    * -------------------------------------------------------
    * |     public      |   public  | protected |  private  |
    * -------------------------------------------------------
    * |   protected     | protected | protected | protected |
    * -------------------------------------------------------
    * |    private      | ����������| ����������| ����������|
    * -------------------------------------------------------
    * 
    * NB: ��������� ���� �������� ���������� ���� � ������ �������!
    */

   int main()
   {
      ChildPrivate cPrivate;
      // cout << cPrivate.parentPrivate << endl;   // ����������
      // cout << cPrivate.parentProtected << endl; // ����������
      // cout << cPrivate.parentPublic << endl;    // ����������

      ChildProtected cProtected;
      // cout << cProtected.parentPrivate << endl;    // private, ������� ����������
      // cout << cProtected.parentProtected << endl;  // protected, ������� ����������
      // cout << cProtected.parentPublic << endl;     // protected, ������� ����������

      ChildPublic cPublic;
      // cout << cPublic.parentPrivate << endl;    // private, ������� ����������
      // cout << cPublic.parentProtected << endl;  // protected, ������� ����������
      cout << cPublic.parentPublic << endl;     // public

      return 0;
   }
}
