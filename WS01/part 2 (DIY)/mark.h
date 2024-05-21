// - Alikhan Ongdassyn,
// - aongdassyn@myseneca.ca,
// - 158486225,
// - 01/23/24.

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef MARK_H
#define MARK_H
namespace seneca {
   /// <summary>
   /// Record of a mark received by a student.
   /// </summary>
   struct Mark
   {
      /// <summary>
      /// The first name of the student.
      /// </summary>
      char m_firstName[20 + 1];
      /// <summary>
      /// The last name of the student.
      /// </summary>
      char m_lastName[30 + 1];
      /// <summary>
      /// The mark the student received (as a number between 0 and 100).
      /// </summary>
      int m_mark;
   };
   bool printReport(const char* filename);
} 
#endif 