#include <cassert>
#include <functional>
#include <tuple>
#include <vector>

#include "benchmark/benchmark.h"

#include "check_unique_chars.hpp"

namespace check_unique_chars {

const std::vector<std::tuple<std::string_view, int, int>> input = {
    {"mjqjpqmgbljsphdztnvjfqwrcgsmlb", 7, 19},
    {"bvwbjplbgvbhsrlpgdmjqwftvncz", 5, 23},
    {"nppdvjthqldpwncqszvftbrmjlhg", 6, 23},
    {"nznrnfrfntjfmvfwmzdfjlvtqnbhcprsg", 10, 29},
    {"zcfzfwzzqfrljwzlrfnpqdbhtmscgvjw", 11, 26},
    {"nfddjzjjjmrjjfttzctzzhqzqbbvhhcfcpcqpcqpccsmsvsswbwzwfffnvfvpfvffhnnrgngzgrrhvhfhvvmjvjcccvppqdppbnbjjzlzflfccjjtctqccrhrnhnqhqwwjssjjhpjjcqqdgghddhfdfbffdpfdfzdddthhrcrbrqrbqqbcbnnwbbzcbzccmqqwllrljjjpqpdpsddmbmccwwgngmmzzzpbpspnprnppprmmwfwffrrpsrrchrrrrdqdfddnvnjnppqmqhhpshhjmhjhzjhhhzllbpbnnngdgzgmmjvvprrhqrhqhpqhqqrnqnddvjvvftfggfcgfffgrghhbmbzzjczzcscrccgbbjbqjbjsbsqbqttbqbfqqqrzrmzrmmcwcmwmrwmwnmnfnjjbdjbbslltjjmgmrmllhbhsbsmsqmqllvjjrvjrjcrrtztjzjbjsbbrjjvbjjgqjjpjsszpszsnznllvmlmfmppbvbzvvddtbtrbttchthjthjhnjnqnqrrllnflnnljnnzjjswjwllpmmpnnqnrrndnnbwwmcmcmbbhjjbbfpfvpvttcvvhshqqznzqqdndldmllpgptgptpbblzlddgqqdmmvpvvrccfvvjrvjjgpggqcggjbgbqqcgqccgppffjppzczmzdmmqppwcwlcwwhccfpcphcctvtzthtzhhnmnvmnnvqnqnpnqqwqsqdsszwzbwwgcwcrrtprrfhhcmcqcdcvdcccnpptgpgwpprsprsrdrtdrtrntrtprtppstsccbwwvnvpnvpnptpqttzbzcznzhzhddfbflfcchvchhplhlwhhlhglhhwqqzlqzlzvlvtlvtvrttglttslslclslqssslclbbrjrpjjcscfsfppjlplhplptlltlflglffdttmffrggfjjmllbnlnbnznqnfffmhhnmmsgmsmfsszggpnnhmhnnpwnndqqlmqmnmtnmtnttvtztlzlnzzsdsnssvhsszcscffcpczpcpffpwfwnwhnntnssptthccbnndppgjgpjpssbnnpgnpppjtjqqzfqqrrbmmbdddzjzvzwzssnpsnspnpvnpppjppvsvffmpffbcffslfsfmsmmqzzmttnsnqsqcsqsbqbcclqqphpttvrtrlrhrthhlppscsrsjjvljlmlwlslblqqqgdsbrzwzjzwcjrwbpfmjtmdgjvbcfvtvmsfjtjcmtlzmsjlnmhcswcmjndggdsmqfmmdngjpvrsbhrchldnhdhfdlwccnfmgbwfzppgzzcvblvsmqbfghrgdwlzdcvpqthgbdlwbrfpsvlgpdqznftswgwvchjfrblbdsqjmzchfhlrjhpbrdgvgrrmhrnrdbrdsfsgzvqfdtnvddbtcjwphrhgpqlzjssrgzjcncjnbrzvhgbwpgtfnqhpspmgptzcgvjqgzpmwtjtzldqnclmplwdpzcppgcbrsnlzfgmlnljjhfzrftnhdfnqchgdqrfcjszvbmdrghwzmjnwgnrlptljzqrwsmcfwvbcjgsfdjhnqgzzztmcgmndbtdwvqmzlfcmhfgpqztwgjdccncdccpgbcvhfzbhhbjhgjpdzcmrwgtvrmzdwjtmlzllmgplpqjwwwvbrzgmvpcvwchcwfgbjtzrfctgvfrpphbnsbjlswrztqmchtzfstzdgdwwvhpdhztbmsrbqmndpgvnwwdtgzcddvmvbjstqmjvtzlzgrhzhvplwnpphctvtlvnpmwfzmqcvrnfmmgtsgbcjpffrvbpqpszfpjsjtzqmcnzhnjnpwtvgfqntnhhjhmbvmlvmqgggrnfmmmsvfsqffbvwtzlfhlbjqhrltzwfstvjqhbbblqdbcmgtjgmzdtpslbzsgnmpzsswjlwdpzpmmvmpntbhnqlwrcrfbghzhwlhhpjqztjjrrfscrtwtnlqlqmdbmbfnvngvvthhghgsvqlqvgvmtjmjtwpcznzqhhfpqqfphcdrtzjjhsffslthzwpmsnltnjmfgpsjgqzdwrtgnhflhrnjwqftpnqgptgvgjptzhhtqhtddsfhppmmqcrsnlnrswpjhqgzbpwzfzptzqzzwltlrmjwjrwdgvvzhshqqrhtzmvqpfljlvpmrzbqpscpvsfdbdbcbdwwhpmldlrgpwslzhtbpgtzscfhjlgwcgbhcbftpftvpggvcdvndqnfvfqbwrjtdcbwpsbqpzmwdhjpmjhjmlcdphrjbgsnmcmvfnrggfvttclmbvsfjpnbndbblnbdfqzmsldlswdrtzqsqppjshtlrtccthmmpjgddbbgfgthnzdffbtrpchzgbvqvjcsnpgbrzrczzmzrmhjrlvvgmsqddjsqmcqfmwnhznbczzjlpmhnfwjtrfgffsjdlwgdwwlvdpdlvszphntrvttczgnwffsdsvjmqbthgcgfjgznrfnbplbvgsjbsglhnrjpbldhmznqgqpvldvhcpmmwzfjdjdbnprtrrnwsszjhmngvmtsrqdqdsprwhjpsqwqbsdtpptwlbfbsvdgrplrvpnfbzwrdsdbvhpgwcnqvwdcswdmdltchnngpmlqvchbnrpzcnfhvlzbwbnmssbhpvvmpcwvrwzpfpssndwwfnrslpjwhwrfsswmgtszrhczcrclpldpwpghgptmzzjjjtvjcnncjpfbcvldbnlnqtsqdswcsrqcfgvwbwdvbdwwzndfvcstjbfngtqqwsbpdjdgqdlsnwgcvmmhrqcqvdbqdqczzwzlfgffbwzbfdnpvprzmqclllsdvctwjfgqbchhmsntlvnlspwtnhgshwrvzccfmfrscqwrvdccwqnrccctjrvvnqbrphrfvfrfldbbthhrdzvdmfbctsmvgwmvpdslgbcpqqdvpsjcdvmctwghdsjtmhhvdswbcvtmsnsztfghnnfhflmmnmdqpvpdplllzgqgnsjwsrgzfwhrwhcscvrgcrgjdghqjfbswtgjsvnpqznrvbdbrplwdmbqhtbcfccnpwqlsdstnpcfpbfgqrzmcqhflmcfvbbnwrrblnfslsrwpwlbvqfhgpdwzmgvftssrvdmhnmwdfqmsvqbltlmmwmjrrhgpgznqbwhcqgphvzqmntbbdhhpnlbbffjgmcdntgwmtblwlzrcdcdbtrllrdnznrrsglnwhtwbrfdrpvgqwsgzwghbtsfwqlchgsnvfmvnzntlsnlwrnjjltrpmhwnzmhrqdlvvzbfgwlwgdsgcjcjfvhbcjgzlqtsljvzcvlppqdszvdbsmgddrtmvbcpbpppcpvhzfsjrmtcpzljbhpnjjmcdwslrhslccpljrtvcscbcltpshpnrqvtdfzbbfqtpbvznvrbflwvbvrhqpzltsdrnqccsfgzzftvjfqslcnmfvwtpdbjhtzwrgvntgnfvqtdrjdgglvrnqfzsbhnvhcdbctthdrjnvwlcsjtmphpvlqjngwjnngmqqnslrrsdfpfbvsvcwjtfmwtbpnnghtvvwlphbnsgflvsfdcqrctvjfjrwqjdmbbcclwvlstbgbfqjgbpbqfwdbpmnvqnfpbhrfhwltmcszpwnvtvhrvpcqhzdppjwttlhgsnvmsrwrnwvgzpbwljjjsjzctftzftvmsstpjnzvmmrgbbpmfmfrszwjdgzfhpvsfdqbbhgvfvqrrtqwlwzwwsnnmmvmlwjzvgrwhmffzwrqwbcdtbtzpspbnqgprdqtzrpmgvnmbsnjnvtzgmhqqtrvltbsrwjlssncdppgpmzqzbzvbpjpfwmvgsbhffzpbctmqvfwhsgdjtwqhrhmgnqpvmpjzhppvcbrpwmdshzcrwzdzcjmhfvjgtbznsmdjphlssmlmbhtmnsqnjfsjwhjvgztnwhmnztqppchngdnhzwpsvqqpzdwgbhcbzvmbnqmghbhgvrqhtfzhgvqdbpvdrjsqrdnhqhrwdlczvtnzwfrqhnffwdvtrnqsmmcjtrhmgbwcmnzbbvdsrlbbtwslhghwprpglpq", 1210, 3476},
};

int find_position(const std::string_view& line, const int length, const std::function<bool(const std::string_view&)>& check)
{
    for (auto it = line.begin(); it != std::prev(line.end(), length - 1); ++it)
        if (check({it, it + length}))
            return static_cast<int>(std::distance(line.begin(), it) + length);

    return -1;
}

int find_position_with_bucket_size(const std::string_view& line, const int length, const std::size_t bucket_size, const std::function<bool(const std::string_view&, std::size_t bucket_size)>& check)
{
    for (auto it = line.begin(); it != std::prev(line.end(), length - 1); ++it)
        if (check({it, it + length}, bucket_size))
            return static_cast<int>(std::distance(line.begin(), it) + length);

    return -1;
}

static void BM_sorted_strings(benchmark::State& state)
{
    for (auto _ : state) {
        for (const auto& [line, expected_result1, expected_result2] : input) {
            const auto result1 = find_position(line, 4, sorted_strings);
            const auto result2 = find_position(line, 14, sorted_strings);

            benchmark::DoNotOptimize(result1);
            benchmark::DoNotOptimize(result2);

            assert(result1 == expected_result1);
            assert(result2 == expected_result2);
        }
    }
}

static void BM_bits(benchmark::State& state)
{
    for (auto _ : state) {
        for (const auto& [line, expected_result1, expected_result2] : input) {
            const auto result1 = find_position(line, 4, bits);
            const auto result2 = find_position(line, 14, bits);

            benchmark::DoNotOptimize(result1);
            benchmark::DoNotOptimize(result2);

            assert(result1 == expected_result1);
            assert(result2 == expected_result2);
        }
    }
}

static void BM_bits_and_early_return(benchmark::State& state)
{
    for (auto _ : state) {
        for (const auto& [line, expected_result1, expected_result2] : input) {
            const auto result1 = find_position(line, 4, bits_and_early_return);
            const auto result2 = find_position(line, 14, bits_and_early_return);

            benchmark::DoNotOptimize(result1);
            benchmark::DoNotOptimize(result2);

            assert(result1 == expected_result1);
            assert(result2 == expected_result2);
        }
    }
}

static void BM_bitset(benchmark::State& state)
{
    for (auto _ : state) {
        for (const auto& [line, expected_result1, expected_result2] : input) {
            const auto result1 = find_position(line, 4, bitset);
            const auto result2 = find_position(line, 14, bitset);

            benchmark::DoNotOptimize(result1);
            benchmark::DoNotOptimize(result2);

            assert(result1 == expected_result1);
            assert(result2 == expected_result2);
        }
    }
}

static void BM_bitset_and_early_return(benchmark::State& state)
{
    for (auto _ : state) {
        for (const auto& [line, expected_result1, expected_result2] : input) {
            const auto result1 = find_position(line, 4, bitset_and_early_return);
            const auto result2 = find_position(line, 14, bitset_and_early_return);

            benchmark::DoNotOptimize(result1);
            benchmark::DoNotOptimize(result2);

            assert(result1 == expected_result1);
            assert(result2 == expected_result2);
        }
    }
}

static void BM_counting_chars(benchmark::State& state)
{
    for (auto _ : state) {
        for (const auto& [line, expected_result1, expected_result2] : input) {
            const auto result1 = find_position(line, 4, counting_chars);
            const auto result2 = find_position(line, 14, counting_chars);

            benchmark::DoNotOptimize(result1);
            benchmark::DoNotOptimize(result2);

            assert(result1 == expected_result1);
            assert(result2 == expected_result2);
        }
    }
}

static void BM_counting_chars_and_early_return(benchmark::State& state)
{
    for (auto _ : state) {
        for (const auto& [line, expected_result1, expected_result2] : input) {
            const auto result1 = find_position(line, 4, counting_chars_and_early_return);
            const auto result2 = find_position(line, 14, counting_chars_and_early_return);

            benchmark::DoNotOptimize(result1);
            benchmark::DoNotOptimize(result2);

            assert(result1 == expected_result1);
            assert(result2 == expected_result2);
        }
    }
}

static void BM_unordered_set(benchmark::State& state)
{
    for (auto _ : state) {
        for (const auto& [line, expected_result1, expected_result2] : input) {
            const auto result1 = find_position_with_bucket_size(line, 4, static_cast<std::size_t>(state.range(0)), unordered_set);
            const auto result2 = find_position_with_bucket_size(line, 14, static_cast<std::size_t>(state.range(0)), unordered_set);

            benchmark::DoNotOptimize(result1);
            benchmark::DoNotOptimize(result2);

            assert(result1 == expected_result1);
            assert(result2 == expected_result2);
        }
    }
}

BENCHMARK(BM_sorted_strings)->Unit(benchmark::kMicrosecond);
BENCHMARK(BM_bits)->Unit(benchmark::kMicrosecond);
BENCHMARK(BM_bits_and_early_return)->Unit(benchmark::kMicrosecond);
BENCHMARK(BM_bitset)->Unit(benchmark::kMicrosecond);
BENCHMARK(BM_bitset_and_early_return)->Unit(benchmark::kMicrosecond);
BENCHMARK(BM_counting_chars)->Unit(benchmark::kMicrosecond);
BENCHMARK(BM_counting_chars_and_early_return)->Unit(benchmark::kMicrosecond);
BENCHMARK(BM_unordered_set)->Unit(benchmark::kMicrosecond)->Arg(8);
BENCHMARK(BM_unordered_set)->Unit(benchmark::kMicrosecond)->Arg(16);
BENCHMARK(BM_unordered_set)->Unit(benchmark::kMicrosecond)->Arg(26);
BENCHMARK(BM_unordered_set)->Unit(benchmark::kMicrosecond)->Arg(32);
BENCHMARK(BM_unordered_set)->Unit(benchmark::kMicrosecond)->Arg(64);
BENCHMARK(BM_unordered_set)->Unit(benchmark::kMicrosecond)->Arg(256);

}  // namespace check_unique_chars
