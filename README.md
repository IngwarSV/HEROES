# ARMY
Practice in OOP

Базовые типы юнитов:
- Unit: воин специализирующийся на нанесении физического урона
- SpellCaster: воин специализирующийся на нанесении магического урона

Юниты, наносящие физический урон:
- Soldier [Солдат] : юнит без всяких специальных возможностей
- Rogue [Разбойник] : разбойника невозможно контратаковать
- Berserker [Берсерк] : на берсеркера не действует магия
- Vampire [Вампир] : при атаке / контратаке потребляет часть жизненных сил противника
- Werewolf [Оборотень] : умеет превращаться в волка (в состоянии волка имеет более высокий показатель жизненных сил и атаки, но получает больший урон от магии)

Юниты, способные к магии:
- Wizard [Волшебник] : атакует боевыми заклинаниями (лечебные заклинания имеют только половину силы)
- Healer [Целитель] : владеет целебными заклинаниями (боевые заклинания имеют только половину силы)
- Priest [Священник] : владеет целебными заклинаниями (боевые заклинания имеют только половину силы), наносит x2 урон нежити (Vampire, Necromancer)
- Warlock [Чернокнижник] : призывает демонов (класс Demon на базе класса Soldier)
- Necromancer [Некромант] : следит за всеми кого атаковал, в случае смерти атакованого юнита, получает часть его жизненных сил

Интерфейсы:
- Observer [наблюдатель] : для Necromancer
- Observable [наблюдаемое] : для всех остальных

- Вынесено механику атаки в виде отдельных классов
- Вынесено заклинания в виде отдельных классов
- Вынесено состояния юнитов в виде отдельных классов

- Разделено урон на физический и магический
- Реализовано волшебникам книгу заклинаний

Дополнительные возможности:
- Вампир может сделать вампиром другого юнита (исключение Werewolf, Demon)
- Оборотень может сделать оборотнем другого юнита (исключение Vampire, Demon)
