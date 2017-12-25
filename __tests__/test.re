open Jest;

open Expect;

test("Raven make empty config", () => expect(Raven.makeConfig()) |> toMatchSnapshot);

test("Raven make config", () => expect(Raven.makeConfig(~level=`info, ())) |> toMatchSnapshot);