1. Комментарии к 1-му заданию:
   1)	Ошибка в классе Foo и его наследнике Bar. Результат удаления массива с помощью конструкции «delete i;»
      не определен, необходимо удалить массив при помощи конструкции «delete[] i;»

   2)	В функции main удаляются объекты f и b. Однако указатели продолжают указывать на удалённые объекты.
   Необходимо присвоить указателям значение nullptr

   3)	Есть смысл использовать конструкцию try - catch после выделения памяти оператором new.
   Если память не выделилась, то оператор new возвращает std::bad alloc. Также необходимо сделать проверку на Null перед освобождением памяти. 

   4)	Деструктор дважды освободит участок памяти, отведенный для f и b, что приведёт к Undefined Behavior.

   5) При создании объекта b класса Bar, являющегося наследником класса Foo, будет вызван конструктор класса Foo, 
  затем конструктор класса Bar. При удалении объекта b будет вызван только деструктор класса Foo. Получаем утечку памяти. 
  Для решения данной проблемы необходимо сделать деструктор класса Bar virtual.  Хорошей практикой является добавление после
  деструктора класса Foo ключевого слова override(компилятор сразу выдаст ошибку, если мы не сделаем деструктор базового класса виртуальным).

2. Комментарии к 2-му заданию:
   Для того, чтобы можно увеличить число используемых языков, я использовал стандартный 
   контейнер std::vector, реализующий динамический массив. Также я добавил функцию добавления языка.
3. Комментарии к 3-му заданию:
   1)	Необходимо сделать проверки выделения памяти на std::bad alloc
   2) Переменная LEGACY_SIZE 3 следовало использовать везде, в том числе в файле legacy.c.
   Да и сам макрос #define LEGACY_SIZE 3 лучше оставить  в файле legacy.c. Если так сделать, то необходимо файл legacy.c подключить к файлу modern.cpp.
   Если #define LEGACY_SIZE 3 оставить в файле modern.cpp, то необходимости подключать legacy.c к modern.cpp нет,
   так как extern переменная видна из всех файлов программы.
   3)	Лучше вместо побитового копирования сделать глубокое копирование, чтобы избежать случая, когда несколько объектов имеют один
      и тот же указатель данных, что означает, что указатель будет удаляться несколько раз. Есть смысл реализовать правило трёх,
      определив деструктор, оператор присваивания и конструктор копирования. Деструктор нужно определить также для освобождения памяти,
     	выделенной при использовании оператора new. Ответственность за удаление объектов, созданных при помощи оператора new, лежит на программисте.
   4)Нужно изменить тип values в modern.cpp  на extern int values[LEGACY_SIZE], для того чтобы получить массив из LEGACY_SIZE элементов.
4. Комментарии к 4-му заданию:
   1)	Массив double* points  удаляется при помощи delete[].
   2)	Забыли закрыть файл "features.dat".
   3)	Переменную следовало бы назвать не Poligon, а Polygon, потому что в английском языке нет слова Poligon.
   4)	Никак не используется возвращаемое значение из функции feature.read(...), которое показывает, были ли считаны все необходимые данные
      (по количеству считанных байт)
   5)	Координаты x, y можно хранить в структуре map
   6)	Нет проверки на корректность выделения памяти для каждой из вершин.

5. Комментарии к 5-му заданию:
   В языке C нет шаблонов, поэтому возможно только написать перегрузки для разных типов данных  для линейного поиска  в массиве.
   Я реализовал линейный поиск для int, char и структуры pair. Также я добавил проверку на нулевые элементы.
6. Комментарии к 6-му заданию:
   Я реализовал односвязный список из структур. Есть функции создания нового списка, добавления элемента в конец списка, добавление нового
   элемента после определенного элемента, обмена узлов списка(с учетом двух ситуаций: когда соседние элементы являются соседями, либо не являются) и
   вывод элементов списка(указателей на void*). 